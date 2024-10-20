#include <gtest/gtest.h>

#include "Bureaucrat.hpp"
#include "Form.hpp"

// 通常の署名
TEST (FormTest, Constructor) {
    Form form("Form", 10, 20);
    EXPECT_EQ(form.getName(), "Form");
    EXPECT_EQ(form.getGradeToSign(), 10);
    EXPECT_EQ(form.getGradeToExecute(), 20);
    EXPECT_EQ(form.isSigned(), false);
}

// 署名グレードが高すぎる
TEST (FormTest, GradeTooHigh) {
    EXPECT_THROW(Form("Form", 0, 20), Form::GradeTooHighException);
    EXPECT_THROW(Form("Form", 10, 0), Form::GradeTooHighException);
    EXPECT_THROW(Form("Form", 0, 0), Form::GradeTooHighException);
}

// 署名グレードが低すぎる
TEST (FormTest, GradeTooLow) {
    EXPECT_THROW(Form("Form", 151, 20), Form::GradeTooLowException);
    EXPECT_THROW(Form("Form", 10, 151), Form::GradeTooLowException);
    EXPECT_THROW(Form("Form", 151, 151), Form::GradeTooLowException);
}

// 署名
TEST (FormTest, BeSigned) {
    Bureaucrat bureaucrat("Bureaucrat", 10);
    Form form("Form", 10, 20);
    form.beSigned(bureaucrat);
    EXPECT_EQ(form.isSigned(), true);
}

// 署名できない
TEST (FormTest, BeSignedFail) {
    Bureaucrat bureaucrat("Bureaucrat", 11);
    Form form("Form", 10, 20);
    EXPECT_THROW(form.beSigned(bureaucrat), Form::GradeTooLowException);
}

// // 実行
// TEST (FormTest, Execute) {
//     Bureaucrat bureaucrat("Bureaucrat", 10);
//     Form form("Form", 10, 20);
//     form.beSigned(bureaucrat);
//     EXPECT_NO_THROW(bureaucrat.executeForm(form));
// }

// // 実行できない
// TEST (FormTest, ExecuteFail) {
//     Bureaucrat bureaucrat("Bureaucrat", 11);
//     Form form("Form", 10, 20);
//     form.beSigned(bureaucrat);
//     EXPECT_THROW(bureaucrat.executeForm(form), Form::GradeTooLowException);
// }

// ストリーム出力
TEST (FormTest, Stream) {
    Form form("Form", 10, 20);
    testing::internal::CaptureStdout();
    std::cout << form;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Form, form sign grade 10, form exec grade 20, form is not signed");
}

