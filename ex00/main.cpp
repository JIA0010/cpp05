#include "Bureaucrat.hpp"

int main() {
    try {
        // デフォルトコンストラクタでオブジェクトを作成
        Bureaucrat defaultBureaucrat;
        std::cout << "Default bureaucrat: " << defaultBureaucrat << std::endl;

        // 名前とグレードを指定してオブジェクトを作成
        Bureaucrat customBureaucrat("John Doe", 75);
        std::cout << "Custom bureaucrat: " << customBureaucrat << std::endl;

        // グレードをインクリメント（グレードが高くなる）
        customBureaucrat.incrementGrade();
        std::cout << "After increment: " << customBureaucrat << std::endl;

        // グレードをデクリメント（グレードが低くなる）
        customBureaucrat.decrementGrade();
        std::cout << "After decrement: " << customBureaucrat << std::endl;

        // グレードが上限を超える場合
        Bureaucrat highGradeBureaucrat("Alice", 1);
        highGradeBureaucrat.incrementGrade(); // ここで例外が発生するはず
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Other exception: " << e.what() << std::endl;
    }

    return 0;
}
