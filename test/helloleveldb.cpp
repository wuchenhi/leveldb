//g++ helloleveldb.cpp -lleveldb -lpthread -lsnappy -I/home/wuyi/cpp_code/leveldb/include/ -L/home/wuyi/cpp_code/leveldb/build -std=c++11 -o hello
#include <cassert>
#include <iostream>
#include "leveldb/db.h"
using namespace std;
using namespace leveldb;

int main() {
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;//没有就创建
    leveldb::Status status = leveldb::DB::Open(options, "testdb", &db);
    assert(status.ok());
    status = db->Put(WriteOptions(), "first", "hello world!");
    assert(status.ok());
    string res;
    status = db->Get(ReadOptions(), "first", &res);
    assert(status.ok());
    cout << res << endl;
    delete db;
    return 0;
}