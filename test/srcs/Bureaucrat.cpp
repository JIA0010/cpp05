#include "TestUtils.hpp"

// Bureaucratがnameを持つ
TEST(BureaucratAttributeTest, nameTest) {
  methodRetvalTest<std::string, Bureaucrat>(new Bureaucrat(), &Bureaucrat::getName, "default");
  methodRetvalTest<std::string, Bureaucrat>(new Bureaucrat("byConstructor", 20), &Bureaucrat::getName, "byConstructor");
}

// Bureaucratがgradeを持つ
TEST(BureaucratAttributeTest, gradeTest) {
  methodRetvalTest<int, Bureaucrat>(new Bureaucrat(), &Bureaucrat::getGrade, 150);
  methodRetvalTest<int, Bureaucrat>(new Bureaucrat("byConstructor", 20), &Bureaucrat::getGrade, 20);
}

// _gradeが1より小さくなると例外が飛ぶ
TEST(BureaucratAttributeTest, gradeTooHighTest) {
  methodThrowTest(new Bureaucrat("tooHigh", 1), &Bureaucrat::incrementGrade, Bureaucrat::GradeTooHighException());
}

// _gradeが150より大きくなると例外が飛ぶ
TEST(BureaucratAttributeTest, gradeTooLowTest) {
  methodThrowTest(new Bureaucrat("tooLow", 150), &Bureaucrat::decrementGrade, Bureaucrat::GradeTooLowException());
}

// _gradeが1~150の範囲内のとき例外が飛ばない
TEST(BureaucratAttributeTest, defaultGradeTest) {
  methodNothrowTest(new Bureaucrat("Default", 42), &Bureaucrat::incrementGrade);
  methodNothrowTest(new Bureaucrat("Default", 2), &Bureaucrat::incrementGrade);
  methodNothrowTest(new Bureaucrat("Default", 150), &Bureaucrat::incrementGrade);
  methodNothrowTest(new Bureaucrat("Default", 149), &Bureaucrat::decrementGrade);
  methodNothrowTest(new Bureaucrat("Default", 1), &Bureaucrat::decrementGrade);
}

// std::string intToString(int value) {
//     return std::to_string(value);
// }


// // 標準出力の内容を確認するテスト
// TEST_F(BureaucratTest, InsertionTest) {
//   // 標準出力をキャプチャ開始
//   testing::internal::CaptureStdout();

//   // テスト対象の関数を呼び出す
//   std::cout << *bureaucrat;

//   // 標準出力のキャプチャ結果を取得
//   std::string actual = testing::internal::GetCapturedStdout();
//   // 望まれる標準出力を定義
//   std::string expect = bureaucrat->getName() + ", bureaucrat grade " + intToString(bureaucrat->getGrade()) + "\n";

//   // 出力が"hello world"であることを確認
//   EXPECT_EQ(actual, expect);
// }

TEST(BureaucratOperatorTest, InsertionTest) {
  insertionOperatorTest(new Bureaucrat(), "default, bureaucrat grade 150\n");
  insertionOperatorTest(new Bureaucrat("ryaoi", 21), "ryaoi, bureaucrat grade 21\n");
}