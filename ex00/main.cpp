#include "Bureaucrat.hpp"

/*
例外処理の違い:

・明確なエラー処理: throw, catch, try を使うと、エラー処理が明確になり、エラーチェックを関数の戻り値に頼らず、コードのロジックに集中できる。
・ネストの回避: 戻り値によるエラー処理では、エラーを逐一チェックする必要があるが、例外処理を使えば複数レベルの関数呼び出しをまたいでエラーを処理できる。
・型安全: catch ブロックでは、例外の型に基づいて異なる処理が可能で、戻り値によるエラー処理に比べて柔軟。
・例外を投げた時点で関数の実行を中断: throw を使うと、そこで関数の実行が中断され、例外がキャッチされるまで制御が移動する。
*/

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
