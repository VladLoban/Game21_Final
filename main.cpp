#include <iostream> //вводи вывод через поток
#include <cstdlib> //позволяет использовать рандом
#include <vector> 
#include <string>
#include <map>
#include <unistd.h> //отвечает за задержку выполнения кода(usleep)

using namespace std; //стандартное пространство имен

/*#######################################################################################
заготовки сообщений для вывода на консоль*/

struct literra //хранит в себе фразы для вывода на консоль
{
    string y_win = "Player WIN!";
    string y_lose = "Player LOSE!";
    string comp_win = "Computer WIN!";
    string comp_lose = "Computer LOSE!";
    string num_y = "You number is ";
    string summ_y = "Your summ is ";
    string num_p1 = "Player 1 number is ";
    string num_p2 = "Player 2 number is ";
    string next_or_stop = "Enter 'y' for new number or 'n' for stop game!";
    string num_comp = "Computer number is ";
    string summ_p1 = "Player 1 summ is ";
    string summ_p2 = "Player 2 summ is ";
    string summ_comp = "Computer summ is ";
    string next_step = "next step";
    string player1 = "player1";
    string player2 = "player2";
    string computer = "computer";
    string check_player = "Would you like to play with player 2 or computer?\n 'p' for player 2 or 'c' for computer";
    string stop_game = "STOP THIS GAME!!!";
};  

/*##################################################################################*/
int gen_chislo(); //генирирует число
void push_in_vector(vector<int> & vec, int num);//помещает генирируемое число в вектор
void summ_number_in_vector(vector<int> & vec, int & num);//сумирует числа в векторе
void game_player(int num_player);//запускает процесс игры игрока 1 и игрока 2
void game_comp();//запускает режим игры компьютера
void check_game();//выбор между 2 игроком и компьютером
void compare_numbers(string num1, string num2);//сравнение результатов результатов игроков и компьютера
void check_num(int & summ, int num_player);//проверка числа на выйгрыш и номера игрока
bool check_game_p(int & summ);//проверяет сумму и упровляет циклом
pair<bool, char> check_num_comp(int & summ);//проверка суммы у компьютера
pair<bool,string> check_vybor(char vybor);//проверка выбора действия y или n
void print(string stroka, int num);//выводит на консоль строку и число
void print(string stroka);//выводит на консоль строку
void print(int num_player, string str);//выводит номер игрока и строку
vector<int> number_player1;//числа первогог игрока
vector<int> number_player2;//числа второго игрока
vector<int> number_comp;//числа компьютера
int summ_player1;//сумма первого игрока
int summ_player2;//сумма второго игрока
int summ_comp;//сумма компьютера
literra pr_str;//объект структуры для доступа к фразам вывода

/*##################################################################################*/
//[INT_MAIN]
int main()
{
    srand((unsigned) time(NULL));//помогает рандому задействовать системное время
    game_player(1);
    return 0;
}

/*##################################################################################*/
//CHECK_GAME_P]
bool check_game_p(int & summ)
{
    if(summ = 21)
    {
        return false;
    }
    else if(summ > 21)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*##################################################################################*/
//[GAME_PLAYER]
void game_player(int num_player)
{  
    int gen_num = 0;
    char vybor;
    bool start_stop_game = true;
    bool next_game = true;
    pair<bool,string> check;
    while(start_stop_game)
    {
        gen_num = gen_chislo();
        if(num_player == 1)
        {
            push_in_vector(number_player1,gen_num);
            print(pr_str.num_p1, gen_num);
        }
        else if(num_player == 2)
        {
            push_in_vector(number_player2,gen_num);
            print(pr_str.num_p2, gen_num);
        }
        
        if(num_player == 1)
        {
            summ_number_in_vector(number_player1,summ_player1);
            print(pr_str.summ_p1,summ_player1);
            next_game = check_game_p(summ_player1);
        }
        else if(num_player == 2)
        {
            summ_number_in_vector(number_player2,summ_player2);
            print(pr_str.summ_p2,summ_player2);
            next_game = check_game_p(summ_player2);
        }
        if(next_game)
        {
            do
            {
                print(pr_str.next_or_stop);
                cin >> vybor;
                check = check_vybor(vybor);
                start_stop_game = check.first;
            }while(check.second == "error");
        }
        else
        {
            start_stop_game = false;
        }

    }
    if(num_player == 1)
    {
        check_num(summ_player1, num_player);
    }
    else if(num_player == 2)
    {
        check_num(summ_player2, num_player);
    }
    
}

/*##################################################################################*/
//[GAME_COMP]
void game_comp()
{
    int gen_num;
    bool start_stop_game = true;
    pair<bool, char> choose;
    while(start_stop_game)
    {
        gen_num = gen_chislo();
        push_in_vector(number_comp,gen_num);
        print(pr_str.num_comp, gen_num);
        summ_number_in_vector(number_comp, summ_comp);
        print(pr_str.summ_comp, summ_comp);
        choose = check_num_comp(summ_comp);
        start_stop_game = choose.first;
        if(choose.second)
        {
            print(pr_str.next_step);
        }
        usleep(1000 * 1000);
    }
    if(choose.second == 'w')
    {
        print(pr_str.y_win);
    }
    else if(choose.second == 'l')
    {
        print(pr_str.y_lose);
    }
    else if(choose.second == 's')
    {
        compare_numbers(pr_str.player1, pr_str.computer);
    }
}

/*##################################################################################*/
//[GEN_CHISLO]
int gen_chislo()
{
    int rand_chislo = 0;
        rand_chislo = 2 + rand()%13;
        if(rand_chislo != 5)
        {
            return rand_chislo;  
        }
}

/*##################################################################################*/
//[PUSH_IN_VECTOR]
void push_in_vector(vector<int> & vec, int num)
{
    vec.push_back(num);
}

/*##################################################################################*/
//[SUMM_NUMBER_IN_VECTOR]
void summ_number_in_vector(vector<int> & vec, int & num)
{
    num = 0;
    for(int i : vec)
    {
        num +=i;
    }
}

/*##################################################################################*/
//[CHECH_VYBOR]
pair<bool,string> check_vybor(char vybor)
{
    if(vybor == 'y')
    {
        return make_pair(true,"yes");
    }
    else if(vybor == 'n')
    {
        return make_pair(false,"no");
    }
    else
    {
        return make_pair(true,"error");
    }
}

/*##################################################################################*/
//[CHECK_NUM]
void check_num(int & summ, int num_player)
{
    if(summ == 21)
    {
        print(num_player, pr_str.y_win);
    }
    else if(summ > 21)
    {
        print(num_player, pr_str.y_lose);
    }
    else if(summ < 21 && num_player == 1)
    {
        check_game();
    }
    else if(summ < 21 && num_player == 2)
    {
        compare_numbers(pr_str.player1, pr_str.player2);
    }
}

/*##################################################################################*/
//[CHECK_NUM_COMP]
pair<bool, char> check_num_comp(int & summ)
{
    if(summ == 21)
    {
        return make_pair(false, 'w');
    }
    else if(summ > 21)
    {
        return make_pair(false, 'l');
    }
    else if(summ == 18 || summ == 19 || summ == 20)
    {
        return make_pair(false, 's');//stop game
    }
    else
    {
        return make_pair(true, 'n');//next
    }
}

/*##################################################################################*/
//[CHECK_GAME]
void check_game()
{
    char check;
    do
    {
        print(pr_str.check_player);
        cin>>check;
    }
    while(check != 'p' || check != 'c');
    if(check == 'c')
    {
        game_comp();
    }
    else if(check == 'p')
    {
        game_player(2);
    }
    else
    {
        print(pr_str.stop_game);
    }
}

/*##################################################################################*/
//[COMPARE_NUMBERS]
void compare_numbers(string num1, string num2)
{
    if(num1 == "player1" && num2 == "player2")
    {
        if(summ_player2 > summ_player2)
        {
            print(1,pr_str.y_win);
        }
        else
        {
            print(2,pr_str.y_win);
        }
    }
    else if(num1 == "player1" && num2 == "computer")
    {
        if(summ_player2 > summ_comp)
        {
            print(1,pr_str.y_win);
        }
        else
        {
            print(pr_str.y_win);
        }
    }
} 
  
/*##################################################################################*/
//[PRINT]
void print(string stroka, int num)
{
    cout<<stroka<<" "<<num<<endl;
}

/*##################################################################################*/
//[PRINT]
void print(string stroka)
{
    cout<<stroka<<endl;
}

/*##################################################################################*/
//[PRINT]
void print(int num_player, string str)
{
    cout<<num_player<<" "<<str<<endl;
}