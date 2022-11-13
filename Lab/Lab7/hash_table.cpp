#include "hash_table.h"
#include <cmath>
#include <iostream>

int HashTable::hashFunction(const std::string &name, int base, int table_size)
{
  int res = 0;
  for (unsigned int i = 0; i < name.size(); i++)
  {
    res = (base * res + name[i] - 'a') % table_size;
  }
  return res;
}

int HashTable::getNextHashTableSize(int now_hash_table_size)
{
  int res = now_hash_table_size * 2;
  bool is_prime = false;
  while (true)
  {
    is_prime = true;
    int sq = sqrt(res);
    for (int i = 2; i <= sq; i++)
    {
      if (res % i == 0)
      {
        is_prime = false;
        break;
      }
    }
    if (is_prime)
      break;
    res++;
  }
  return res;
}

HashTable::HashTable(int init_size, int maximum_probe_num,
                     ProbeMode probe_mode)
{ // Task 1

  base_1_ = 37;
  base_2_ = 41;

  hash_table_size_ = init_size;
  maximum_probe_num_ = maximum_probe_num;
  probe_mode_ = probe_mode;

  table_ = new HashCell[hash_table_size_];

  for (int i = 0; i < hash_table_size_; ++i)
  {
    table_[i] = {HashCellState(0), nullptr};
  }
  if (probe_mode_ == ProbeMode(0))
  {
    probe_func_ = [](int hash_value1, int hash_value2, int num_probe, int hash_table_size)
    { int p = (hash_value1+num_probe)%hash_table_size; std::cout << "Probing for the position: " << p << std::endl; return p; };
  }

  if (probe_mode_ == ProbeMode(1))
  {
    probe_func_ = [](int hash_value1, int hash_value2, int num_probe, int hash_table_size)
    { int p = (hash_value1+(num_probe*num_probe))%hash_table_size; std::cout << "Probing for the position: " << p << std::endl; return p; };
  }

  if (probe_mode_ == ProbeMode(2))
  {
    probe_func_ = [](int hash_value1, int hash_value2, int num_probe, int hash_table_size)
    { int p = ((num_probe*hash_value2)+hash_value1)%hash_table_size ;std::cout << "Probing for the position: " << p << std::endl; return p; };
  }
}

HashTable::~HashTable()
{ // Task 1

  for (int i = 0; i < hash_table_size_; ++i)
  {
    if (table_[i].state == HashCellState(1))
    {
      // std::cout<<"test"<<table_[i].student->name();
      // delete table_[i].student;
    }
  }
  delete[] table_;
}

bool HashTable::add(const std::string &name, int score)
{ // Task 2 & 5
  int hash_value1 = hashFunction(name, base_1_, hash_table_size_);
  int hash_value2 = hashFunction(name, base_2_, hash_table_size_);

  if (hash_value2 == 0)
    hash_value2 = 1;
  for (int i = 0; i <= maximum_probe_num_ - 1; ++i)
  {

    int num_probe = probe_func_(hash_value1, hash_value2, i, hash_table_size_);

    // std::cout << "h1 "<<hash_value1<<" h2 "<<hash_value2<<" num_probe "<<num_probe<<" i "<<i<<" hash siez "<<hash_table_size_<<std::endl;
    if (table_[num_probe].state == HashCellState::Active && table_[num_probe].student->name() == name)
    {
      return false;
    }
    if (table_[num_probe].state != HashCellState::Active && table_[num_probe].student == nullptr)
    {
      table_[num_probe].state = HashCellState::Active;
      table_[num_probe].student = new Student(name, score);
      return true;
    }
  }

  if (reHash(getNextHashTableSize(hash_table_size_)))
  {
    // add new item
    add(name, score);
    return true;
  }
  return false;
}

int HashTable::search(const std::string &name) const
{ // Task 3
  int hash_value1 = hashFunction(name, base_1_, hash_table_size_);
  int hash_value2 = hashFunction(name, base_2_, hash_table_size_);

  if (hash_value2 == 0)
    hash_value2 = 1;
  for (int i = 0; i < hash_table_size_; ++i)
  {
    // std::cout << "TEST "<<std::endl;
    int num_probe = probe_func_(hash_value1, hash_value2, i, hash_table_size_);
    if (num_probe >= hash_table_size_)
      return -1;
    if (table_[num_probe].state == HashCellState::Empty)
      return -1;

    if (table_[num_probe].state == HashCellState::Active && table_[num_probe].student->name() == name)
      return table_[num_probe].student->score();
  }

  return -1;
}

bool HashTable::remove(const std::string &name)
{ // Task 4

  int hash_value1 = hashFunction(name, base_1_, hash_table_size_);
  int hash_value2 = hashFunction(name, base_2_, hash_table_size_);

  if (hash_value2 == 0)
    hash_value2 = 1;
  for (int i = 0; i < hash_table_size_; ++i)
  {
    // std::cout << "TEST "<<i<<std::endl;
    int num_probe = probe_func_(hash_value1, hash_value2, i, hash_table_size_);
    if (num_probe >= hash_table_size_)
      return false;
    if (table_[num_probe].state == HashCellState::Empty)
      return false;

    if (table_[num_probe].state == HashCellState::Active && table_[num_probe].student->name() == name)
    {
      // std::cout << "TEST2 "<<i<<std::endl;
      delete table_[num_probe].student;
      table_[num_probe].student = nullptr;
      table_[num_probe].state = HashCellState::Deleted;
      return true;
    }
  }

  return false;
}

void HashTable::reHashUntilSuccess()
{
  int next_hash_table_size = getNextHashTableSize(hash_table_size_);
  while (true)
  {
    if (reHash(next_hash_table_size))
    {
      return;
    }
    next_hash_table_size = getNextHashTableSize(next_hash_table_size);
  }
}

bool HashTable::reHash(int rehash_table_size)
{ // Task 5

  HashCell *newtable_;

  newtable_ = new HashCell[rehash_table_size];

  for (int i = 0; i < rehash_table_size; ++i)
  {
    newtable_[i] = {HashCellState(0), nullptr};
  }

  // Start

  for (int k = 0; k < hash_table_size_; ++k)
  {
    if (table_[k].state == HashCellState::Active)
    {
      bool done = 0;
       //std::cout<<"K loop:"<<k<<"  "<<table_[k].student->name()<<"  "<<std::endl;

      int hash_value1 = hashFunction(table_[k].student->name(), base_1_, rehash_table_size);
      int hash_value2 = hashFunction(table_[k].student->name(), base_2_, rehash_table_size);

      if (hash_value2 == 0)
        hash_value2 = 1;
      for (int i = 0; i <= maximum_probe_num_ - 1; ++i)
      {
        //std::cout<<"From Rehash:"<<i<<"  "<<std::endl;
        int num_probe = probe_func_(hash_value1, hash_value2, i, rehash_table_size);

        

        if (newtable_[num_probe].state == HashCellState::Active && newtable_[num_probe].student->name() == table_[k].student->name())
        {
          i=99;
        }
        if (newtable_[num_probe].state != HashCellState::Active && newtable_[num_probe].student == nullptr && done == 0)
        {
          //std::cout << "hash_value1: "<<hash_value1<<" hash_value2: "<<hash_value2<<" num_probe: "<<num_probe<<" i: "<<i<<" hash size: "<<rehash_table_size<<std::endl;
          newtable_[num_probe].state = HashCellState::Active;
          newtable_[num_probe].student = new Student(table_[k].student->name(), table_[k].student->score());
          done = 1;
          i=99;
        }
      }

    }
  }

  delete[] table_;
  table_ = newtable_;
  hash_table_size_ = rehash_table_size;

  return true;
}

void HashTable::print() const
{
  std::cout << "hash_table_size:" << hash_table_size_ << std::endl;
  for (int i = 0; i < hash_table_size_; i++)
  {
    std::cout << i << ": state = ";
    if (table_[i].state == HashCellState::Empty)
    {
      std::cout << "Empty" << std::endl;
    }
    else if (table_[i].state == HashCellState::Deleted)
    {
      std::cout << "Deleted" << std::endl;
    }
    else if (table_[i].state == HashCellState::Active)
    {
      std::cout << "Active ";
      std::cout << "Student = (" << table_[i].student->name() << ", "
                << table_[i].student->score() << ")" << std::endl;
    }
  }
}
