//g++ helloleveldb.cpp -lleveldb -lpthread -lsnappy -I/home/wuyi/cpp_code/leveldb/include/ -L/home/wuyi/cpp_code/leveldb/build -std=c++11 -o hello
#include <cassert>
#include <iostream>
#include "leveldb/db.h"
using namespace std;
using namespace leveldb;

int main() {
    leveldb::DB* db;
    leveldb::Options options;
    //没有就创建
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "testdb", &db);
    assert(status.ok());
    //写
    status = db->Put(WriteOptions(), "first", "hello world!");
    assert(status.ok());
    string res;
    //读
    status = db->Get(ReadOptions(), "first", &res);
    assert(status.ok());
    cout << res << endl;
    delete db;
    return 0;
}