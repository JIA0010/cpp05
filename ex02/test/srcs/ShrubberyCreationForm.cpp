#include <gtest/gtest.h>

#include <fstream>  //  for File I/O

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


//  ShrubberyCreationFormのテストクラス(テストフィクスチャクラス)
class ShrubberyCreationFormTest : public ::testing::Test {
 protected:
  //  テストの前に実行される処理
  void SetUp() override {
    //  テスト用にShrubberyCreationFormオブジェクトを初期化
    form = new ShrubberyCreationForm("target");
  }
  //  テストの後に実行される処理
  void TearDown() override { delete form; }
  //  テストで使うメンバ変数
  ShrubberyCreationForm* form;
};

// AFormクラスを継承するShrubberyCreationFormクラスが存在する
TEST(ShrubberyCreationFormAttributeTest, inheritAFromTest) {
  ShrubberyCreationForm* defaultName = new ShrubberyCreationForm();
  EXPECT_EQ(defaultName->getName(), "default");
  EXPECT_EQ(defaultName->getGradeToSign(), 145);
  EXPECT_EQ(defaultName->getGradeToExecute(), 137);
  delete defaultName;

  ShrubberyCreationForm* byConstructor =
      new ShrubberyCreationForm("byConstructor");
  EXPECT_EQ(byConstructor->getName(), "ShrubberyCreationForm");
  EXPECT_EQ(byConstructor->getGradeToSign(), 145);
  EXPECT_EQ(byConstructor->getGradeToExecute(), 137);
  delete byConstructor;
}

// ShrubberyCreationFormクラスが_targetを持つ
TEST(ShrubberyCreationFormAttributeTest, targetTest) {
  ShrubberyCreationForm* defaultTarget = new ShrubberyCreationForm();
  EXPECT_EQ(defaultTarget->getTarget(), "default");
  delete defaultTarget;

  ShrubberyCreationForm* byConstructor =
      new ShrubberyCreationForm("byConstructor");
  EXPECT_EQ(byConstructor->getTarget(), "byConstructor");
  delete byConstructor;
}