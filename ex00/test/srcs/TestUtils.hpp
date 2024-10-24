#pragma once
#include <gtest/gtest.h>

//メモ
// TESTの中身はEXPECT_EQだけあればいいので、できるだけシンプルに書く

#include "Bureaucrat.hpp"

// Bureaucratのテストクラス(テストフィクスチャクラス)
class BureaucratTest : public ::testing::Test {
 protected:
  // テストの前に実行される処理
  void SetUp() override {
    // テスト用にBureaucratオブジェクトを初期化
    bureaucrat = new Bureaucrat(DEFAULT_NAME, DEFAULT_GRADE);
  }
  // テストの後に実行される処理
  void TearDown() override { delete bureaucrat; }
  // テストで使うメンバ変数
  Bureaucrat* bureaucrat;
};

// void getNameTest(const Bureaucrat* newedConstructor, const std::string &expect) {
//   EXPECT_EQ(newedConstructor->getName(), expect);
//   delete newedConstructor;
// }

// void getGradeTest(const Bureaucrat* newedConstructor, int expect) {
//   EXPECT_EQ(newedConstructor->getGrade(), expect);
//   delete newedConstructor;
// }

// メソッドの返り値を検証するテスト
template<typename ReturnType, typename ClassType>
void methodRetvalTest(const ClassType* newedInstance, ReturnType (ClassType::*method)() const, const ReturnType& expect) {
    EXPECT_EQ((newedInstance->*method)(), expect);
    delete newedInstance;
}

// メソッドから飛ぶ例外を検証するテスト
template<typename ClassType>
void methodThrowTest(ClassType* newdInstance, void (ClassType::*method)(), const std::exception& expect) {
  try {
    (newdInstance->*method)();  // 関数ポインタを使ってメソッドを実行
  }
  catch (const std::exception& actual) {
    EXPECT_EQ(std::string(actual.what()), std::string(expect.what()));
  }
  delete newdInstance;
}

// メソッドから例外が飛ばないことを検証するテスト
template<typename ClassType>
void methodNothrowTest(ClassType* newdInstance, void (ClassType::*method)()) {
  EXPECT_NO_THROW((newdInstance->*method)());  // 関数ポインタを使ってメソッドを実行
  delete newdInstance;
}

// 挿入演算子の標準出力を検証する汎用テスト関数
template<typename ClassType>
void insertionOperatorTest(const ClassType* newedInstance, const std::string& expect) {
  testing::internal::CaptureStdout();
  std::cout << *newedInstance;
  std::string actual = testing::internal::GetCapturedStdout();

  EXPECT_EQ(actual, expect);
  delete newedInstance;
}
