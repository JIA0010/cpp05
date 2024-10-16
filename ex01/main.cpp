#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // テストケース 1: 正常な署名
    try {
        Bureaucrat asan("Asan", 20);
        Form contract("Contract", 25, 30);

        asan.signForm(contract);
        std::cout << contract << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // テストケース 2: 署名グレードが高すぎる
    try {
        Bureaucrat bsan("Bsan", 1);
        Form topSecret("TopSecret", 0, 10); // Invalid grade

        bsan.signForm(topSecret);
        std::cout << topSecret << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // テストケース 3: 署名グレードが低すぎる
    try {
        Bureaucrat csan("Csan", 100);
        Form report("Report", 50, 50);

        csan.signForm(report);
        std::cout << report << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // テストケース 4: フォームのコピーコンストラクタ
    try {
        Bureaucrat dsan("Dsan", 50);
        Form application("Application", 45, 45);
        
        Form copyApplication(application);
        dsan.signForm(copyApplication);
        std::cout << copyApplication << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // テストケース 5: 署名済みのフォームを再度署名
    try {
        Bureaucrat esan("Esan", 40);
        Form memo("Memo", 45, 45);

        esan.signForm(memo);
        esan.signForm(memo); // 再度署名を試みる
        std::cout << memo << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // テストケース 6: 例外のキャッチ
    try {
        Bureaucrat fsan("Fsan", 5);
        Form secretDoc("SecretDoc", 2, 2);

        fsan.signForm(secretDoc);
        std::cout << secretDoc << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
