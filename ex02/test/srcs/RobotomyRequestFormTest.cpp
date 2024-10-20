#include <gtest/gtest.h>

#include <fstream>  //  for File I/O

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

//  RobotomyRequestFormのテストクラス(テストフィクスチャクラス)
class RobotomyRequestFormTest : public ::testing::Test {
 protected:
  //  テストの前に実行される処理
  void SetUp() override {
    //  テスト用にRobotomyRequestFormオブジェクトを初期化
    form = new RobotomyRequestForm("target");
  }
  //  テストの後に実行される処理
  void TearDown() override { delete form; }
  //  テストで使うメンバ変数
  RobotomyRequestForm* form;
};

// AFormクラスを継承するRobotomyRequestFormクラスが存在する
TEST(RobotomyRequestFormAttributeTest, inheritAFromTest) {
  RobotomyRequestForm* defaultName = new RobotomyRequestForm();
  EXPECT_EQ(defaultName->getName(), "default");
  EXPECT_EQ(defaultName->getGradeToSign(), 72);
  EXPECT_EQ(defaultName->getGradeToExecute(), 45);
  delete defaultName;

  RobotomyRequestForm* byConstructor =
      new RobotomyRequestForm("byConstructor");
  EXPECT_EQ(byConstructor->getName(), "RobotomyRequestForm");
  EXPECT_EQ(byConstructor->getGradeToSign(), 72);
  EXPECT_EQ(byConstructor->getGradeToExecute(), 45);
  delete byConstructor;
}

// RobotomyRequestFormクラスが_targetを持つ
TEST(RobotomyRequestFormAttributeTest, targetTest) {
  RobotomyRequestForm* defaultTarget = new RobotomyRequestForm();
  EXPECT_EQ(defaultTarget->getTarget(), "default");
  delete defaultTarget;

  RobotomyRequestForm* byConstructor =
      new RobotomyRequestForm("byConstructor");
  EXPECT_EQ(byConstructor->getTarget(), "byConstructor");
  delete byConstructor;
}

