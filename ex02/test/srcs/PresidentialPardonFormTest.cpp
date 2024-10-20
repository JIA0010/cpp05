#include <gtest/gtest.h>

#include <fstream>  //  for File I/O

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

//  PresidentialPardonFormのテストクラス(テストフィクスチャクラス)
class PresidentialPardonFormTest : public ::testing::Test {
 protected:
  //  テストの前に実行される処理
  void SetUp() override {
    //  テスト用にPresidentialPardonFormオブジェクトを初期化
    form = new PresidentialPardonForm("target");
  }
  //  テストの後に実行される処理
  void TearDown() override { delete form; }
  //  テストで使うメンバ変数
  PresidentialPardonForm* form;
};

// AFormクラスを継承するPresidentialPardonFormクラスが存在する
TEST(PresidentialPardonFormAttributeTest, inheritAFromTest) {
  PresidentialPardonForm* defaultName = new PresidentialPardonForm();
  EXPECT_EQ(defaultName->getName(), "default");
  EXPECT_EQ(defaultName->getGradeToSign(), 25);
  EXPECT_EQ(defaultName->getGradeToExecute(), 5);
  delete defaultName;

  PresidentialPardonForm* byConstructor =
      new PresidentialPardonForm("byConstructor");
  EXPECT_EQ(byConstructor->getName(), "PresidentialPardonForm");
  EXPECT_EQ(byConstructor->getGradeToSign(), 25);
  EXPECT_EQ(byConstructor->getGradeToExecute(), 5);
  delete byConstructor;
}

// PresidentialPardonFormクラスが_targetを持つ
TEST(PresidentialPardonFormAttributeTest, targetTest) {
  PresidentialPardonForm* defaultTarget = new PresidentialPardonForm();
  EXPECT_EQ(defaultTarget->getTarget(), "default");
  delete defaultTarget;

  PresidentialPardonForm* byConstructor =
      new PresidentialPardonForm("byConstructor");
  EXPECT_EQ(byConstructor->getTarget(), "byConstructor");
  delete byConstructor;
}

// PresidentialPardonFormクラスがexecuteメソッドを持つことを確認するテスト
TEST(PresidentialPardonFormTest, ExecuteMethodExists) {
    // テスト対象のオブジェクトを作成
    PresidentialPardonForm form("Target");

    // テスト用Bureaucratを作成
    Bureaucrat bureaucrat("Zafod", 1);  // 高い権限を持つBureaucrat

    // フォームにサインする
    form.beSigned(bureaucrat);

    // 標準出力のキャプチャ開始
    testing::internal::CaptureStdout();

    // executeメソッドを呼び出す
    form.execute(bureaucrat);

    // 標準出力のキャプチャ結果を取得
    std::string output = testing::internal::GetCapturedStdout();

    // 正しい出力が行われたことを確認
    EXPECT_EQ(output, "Target has been pardoned by Zafod Beeblebrox\n");
}
