#include <gtest/gtest.h>

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

// Bureaucratがnameを持つ
TEST(BureaucratAttributeTest, nameTest) {
  Bureaucrat* defaultName = new Bureaucrat();
  EXPECT_EQ(defaultName->getName(), DEFAULT_NAME);
  delete defaultName;

  Bureaucrat* byConstructor = new Bureaucrat("byConstructor", 20);
  EXPECT_EQ(byConstructor->getName(), "byConstructor");
  delete byConstructor;
}

// Bureaucratがgradeを持つ
TEST(BureaucratAttributeTest, gradeTest) {
  Bureaucrat* defaultGrade = new Bureaucrat();
  EXPECT_EQ(defaultGrade->getGrade(), DEFAULT_GRADE);
  delete defaultGrade;

  Bureaucrat* byConstructor = new Bureaucrat("byConstructor", 20);
  EXPECT_EQ(byConstructor->getGrade(), 20);
  delete byConstructor;
}

// _gradeが1より小さくなると例外が飛ぶ
TEST(BureaucratAttributeTest, gradeTooHighTest) {
  Bureaucrat* tooHighGrade = new Bureaucrat("tooHigh", 1);
  // スローされる
  EXPECT_THROW(tooHighGrade->incrementGrade(),
               Bureaucrat::GradeTooHighException);
  delete tooHighGrade;
}

// _gradeが150より大きくなると例外が飛ぶ
TEST(BureaucratAttributeTest, gradeTooLowTest) {
  Bureaucrat* tooLowGrade = new Bureaucrat("tooLow", 150);
  // スローされる
  EXPECT_THROW(tooLowGrade->decrementGrade(),
               Bureaucrat::GradeTooLowException);
  delete tooLowGrade;
}


// _gradeが1~150の範囲内のとき例外が飛ばない
TEST(BureaucratAttributeTest, defaultGradeTest) {
  Bureaucrat* defaultGrade_42 = new Bureaucrat("Default", 42);
  EXPECT_NO_THROW(defaultGrade_42->incrementGrade());
  delete defaultGrade_42;

  Bureaucrat* defaultGrade_2 = new Bureaucrat("Default", 2);
  EXPECT_NO_THROW(defaultGrade_2->incrementGrade());
  delete defaultGrade_2;

  Bureaucrat* defaultGrade_150 = new Bureaucrat("Default", 150);
  EXPECT_NO_THROW(defaultGrade_150->incrementGrade());
  delete defaultGrade_150;

  Bureaucrat* defaultGrade_149 = new Bureaucrat("Default", 149);
  EXPECT_NO_THROW(defaultGrade_149->decrementGrade());
  delete defaultGrade_149;
    
  Bureaucrat* defaultGrade_1 = new Bureaucrat("Default", 1);
  EXPECT_NO_THROW(defaultGrade_1->decrementGrade());
  delete defaultGrade_1;
}

std::string intToString(int value) {
    return std::to_string(value);
}

// 標準出力の内容を確認するテスト
TEST_F(BureaucratTest, InsertionTest) {
  // 標準出力をキャプチャ開始
  testing::internal::CaptureStdout();

  // テスト対象の関数を呼び出す
  std::cout << *bureaucrat;

  // 標準出力のキャプチャ結果を取得
  std::string actual = testing::internal::GetCapturedStdout();
  // 望まれる標準出力を定義
  std::string expect = bureaucrat->getName() + ", bureaucrat grade " +
                       intToString(bureaucrat->getGrade()) + "\n";

  // 出力が"hello world"であることを確認
  EXPECT_EQ(actual, expect);
}