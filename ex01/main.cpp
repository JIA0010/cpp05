#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // テストケース 1: 正常な署名
    try {
        Bureaucrat alice("Alice", 20);
        Form contract("Contract", 25, 30);

        alice.signForm(contract);
        std::cout << contract << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // テストケース 2: 署名グレードが高すぎる
    try {
        Bureaucrat charlie("Charlie", 1);
        Form topSecret("TopSecret", 0, 10); // Invalid grade

        charlie.signForm(topSecret);
        std::cout << topSecret << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // テストケース 3: 署名グレードが低すぎる
    try {
        Bureaucrat dave("Dave", 100);
        Form report("Report", 50, 50);

        dave.signForm(report);
        std::cout << report << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // テストケース 4: フォームのコピーコンストラクタ
    try {
        Bureaucrat eve("Eve", 50);
        Form application("Application", 45, 45);
        
        Form copyApplication(application);
        eve.signForm(copyApplication);
        std::cout << copyApplication << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // テストケース 5: 署名済みのフォームを再度署名
    try {
        Bureaucrat frank("Frank", 40);
        Form memo("Memo", 45, 45);

        frank.signForm(memo);
        frank.signForm(memo); // Attempt to sign again
        std::cout << memo << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // テストケース 6: 例外のキャッチ
    try {
        Bureaucrat grace("Grace", 5);
        Form secretDoc("SecretDoc", 2, 2);

        grace.signForm(secretDoc);
        std::cout << secretDoc << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
