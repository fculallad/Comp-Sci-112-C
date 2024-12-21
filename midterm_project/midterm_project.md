# Midterm Project

## main.c

```c

#include <stdio.h>
#include "welcome.h"
#include "helloWorld.h"
#include "menu.h"


int main(int argc, char *argv[]) {

  welcome(argc); 
  menu(argc, argv); //Display Menu & Accepts input
  
  return 0;
}

```

## array-of-games.c

```c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h> 
#define GAME_EXIT -1
#define BOARD_SIZE 3
#define EMPTY ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EXIT_GAME -1

//RETURN GAME TITLES
char *ascii_char_get_title(){
  return "Guess ASCII Char Game";
}
char *ansi_c_get_title(){
  return "Guess ANSI C Keyword";
}
char *tic_tac_toe_get_title(){
  return "Tic-Tac-Toe";
}


//GUESS ASCII CHAR GAME
static char *games[3] = { 0 };
static char asciiTable[128] = { 0 };
static void initTable(){
  asciiTable[48] = '0';
  asciiTable[49] = '1';
  asciiTable[0x32] = '2';
  asciiTable[0x33] = '3';
  asciiTable[0x34] = '4';
  asciiTable[0x35] = '5';
  asciiTable[0x36] = '6';
  asciiTable[0x37] = '7';
  asciiTable[0x38] = '8';
  asciiTable[0x39] = '9';
}
static int getRandomIndex(){
  time_t now = time(NULL);
  srand(now);
  int choice = rand() % 10;
  return 0x30 + choice;
}
static void displayMenuChoices(){

  games[0] = ascii_char_get_title();
  games[1] = ansi_c_get_title();
  games[2] = tic_tac_toe_get_title();
  
  int numArrayEntries = sizeof(games) / sizeof(games[0]);
  printf("\nnumArrayEntries: %d\n\n", numArrayEntries);
  for(int i = 0; i < numArrayEntries; i++){
    printf("%d - %s\n", i, games[i]);
  }
  printf("\nSelect number or %d to exit: ", GAME_EXIT);
}
static int getMenuChoice(int choice) {
    printf("Enter your choice: ");
    if(scanf("%d", &choice) != 1) {
      while(getchar() != '\n');
      choice = GAME_EXIT; 
    }
    return choice;
}
int ascii_char_play(){
  initTable();
  int answer = getRandomIndex();
  printf("ASCII value of 0x%x is what char: ", answer);
  int playing = -1;
  do {
    char choice;
    scanf(" %c", &choice);    
    while(getchar() != '\n');

    if(choice >= '0' && choice <= '9') {
      if(choice == asciiTable[answer]){
        printf("\n****Correct!****\n");
        playing = 0;
      }
      else { 
        printf("TRY AGAIN\n");
      }
    } else {
      printf("Please enter a valid digit\n");
    }
  } while (playing == -1);
  return 0;
}


//GUESS ANSI C WORD GAME
static const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};
static const int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
static void display_instructions1() {
    printf("\n=== ANSI C KEYWORD GUESSING GAME ===\n");
    printf("Try to guess the ANSI C keyword!\n");
    printf("Rules:\n");
    printf("1. You have 5 attempts to guess the keyword\n");
    printf("2. After each guess, you'll get hints:\n");
    printf("   - Whether the word is longer or shorter\n");
    printf("   - The first letter of the keyword\n");
    printf("3. Enter 'quit' to exit the game\n\n");
}
static void give_hint(const char *keyword, const char *guess) {
    printf("Hints:\n");
    printf("- The keyword %s than your guess\n", 
           strlen(keyword) > strlen(guess) ? "is longer" : "is shorter");
    printf("- The keyword starts with the letter '%c'\n", keyword[0]);
}
int ansi_c_play() {
    srand(time(NULL));
    int score = 0;
    char guess[50];
    int attempts_left;

      display_instructions1();

    while (1) {

        int random_index = rand() % num_keywords;
        const char *current_keyword = keywords[random_index];
        attempts_left = 5;

        printf("\nNew word selected! (Length: %lu letters)\n", strlen(current_keyword));

        while (attempts_left > 0) {
            printf("\nAttempts left: %d\n", attempts_left);
            printf("Enter your guess (or 'quit' to exit): ");

            if (scanf("%49s", guess) != 1) {
                while (getchar() != '\n'); 
                continue;
            }
            while (getchar() != '\n'); 


            if (strcmp(guess, "quit") == 0) {
                printf("\nGame terminated. Final score: %d\n", score);
                return score;
            }


            if (strcmp(guess, current_keyword) == 0) {
                printf("\n🎉 Correct! The keyword was '%s'\n", current_keyword);
                score += attempts_left;
                printf("Score: +%d points\n", attempts_left);
                break;
            } else {
                printf("\nIncorrect guess!\n");
                give_hint(current_keyword, guess);
                attempts_left--;

                if (attempts_left == 0) {
                    printf("\nGame Over! The keyword was: %s\n", current_keyword);
                }
            }
        }

        printf("\nCurrent total score: %d\n", score);
        printf("\nWould you like to play again? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        while (getchar() != '\n'); 

        if (choice != 'y' && choice != 'Y') {
            printf("\nThanks for playing! Final score: %d\n", score);
            break;
        }
    }

    return score;
}


//TIC-TAC-TOE
static char board[BOARD_SIZE][BOARD_SIZE];
static void display_instructions() {
  printf("\nINSTRUCTIONS\n\n");
  printf("Player 1: X, Player 2: O\n");
  printf("Enter row (1-3) and column (1-3) separated by space\n");
  printf("Enter '-1 -1' at any time to exit the game\n\n");
}
static void init_board() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}
static void display_board() {
    printf("\n");
    printf("     Column\n");
    printf("    1   2   3\n");
    printf("Row  ---------\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d  %c | %c | %c \n", i+1, board[i][0], board[i][1], board[i][2]);
        if(i < BOARD_SIZE-1) {
            printf("   ---+---+---\n");
        }
    }
    printf("\nEnter -1 -1 to exit game\n\n");
}
static int is_valid_move(int row, int col) {

    if(row == EXIT_GAME && col == EXIT_GAME) {
        return 2;
    }

    row--;
    col--;
    if(row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return 0;
    }
    return board[row][col] == EMPTY ? 1 : 0;
}
static int check_winner() {

    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board[i][0] != EMPTY && 
           board[i][0] == board[i][1] && 
           board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // columns
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board[0][i] != EMPTY && 
           board[0][i] == board[1][i] && 
           board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // diagonals
    if(board[0][0] != EMPTY && 
       board[0][0] == board[1][1] && 
       board[1][1] == board[2][2]) {
        return 1;
    }

    if(board[0][2] != EMPTY && 
       board[0][2] == board[1][1] && 
       board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}
static int is_board_full() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}
int tic_tac_toe_play() {
    init_board();
    int current_player = 0; // 0 for X, 1 for O
    int row, col;

    printf("\n=== TIC-TAC-TOE ===\n");
    display_instructions();

    while(1) {
        display_board();
        printf("Player %d's turn (%c)\n", 
               current_player + 1, 
               current_player == 0 ? PLAYER_X : PLAYER_O);
        printf("Enter row and column (1-3) or -1 -1 to exit: ");

        if(scanf("%d %d", &row, &col) != 2) {
            printf("\nError: Please enter two numbers separated by a space!\n");
            while(getchar() != '\n');
            continue;
        }
        while(getchar() != '\n'); 
        int move_status = is_valid_move(row, col);

        if(move_status == 2) {
            printf("\nRETURNING TO MAIN MENU. . . \n\n");
            sleep(1);
            return EXIT_GAME;
        }

        if(move_status == 0) {
            printf("\nInvalid move! The position should be:\n");
            printf("- Row and column between 1 and 3\n");
            printf("- Position must be empty\n");
            printf("- Or enter -1 -1 to exit\n");
            continue;
        }


        board[row-1][col-1] = current_player == 0 ? PLAYER_X : PLAYER_O;

        if(check_winner()) {
            display_board();
            printf("\n Player %d (%c) wins! \n", 
                   current_player + 1, 
                   current_player == 0 ? PLAYER_X : PLAYER_O);
            return current_player + 1;
        }

        if(is_board_full()) {
            display_board();
            printf("\n DRAW \n");
            return 0;
        }

        current_player = !current_player;
    }

    return 0;
}


//Handle Game Choice
void playGames(){

  int choice;
  
  while(1){
  displayMenuChoices();
  choice = getMenuChoice(choice);
  if(choice == GAME_EXIT) break;

  switch(choice){
    case 0 : ascii_char_play(); break;
    case 1 : ansi_c_play(); return; break;
    case 2 : tic_tac_toe_play(); return; break;
  }
  }
}

void shutdown(){
  printf("SHUTTING DOWN!");
  exit(1);
}

void arrayOfGames(){
  playGames();
  shutdown();
}

```

## calculator.c

```c

#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"



int sum(int firstNum, int secondNum){
  return firstNum + secondNum;
}
int sub(int firstNum, int secondNum){
  return firstNum - secondNum;
}
int mult(int firstNum, int secondNum){
  return firstNum * secondNum;
}
int divide(int firstNum, int secondNum){
  return firstNum / secondNum;
}
int rem(int firstNum, int secondNum){
  return firstNum % secondNum;
}

void calculator(int firstNum, int secondNum, int fromCLI, char op){
  int result;

  puts("\n================================");
  puts("          CALCULATOR");
  puts("================================\n");
  
  while(1){

  //Skip prompt if input is from CLI
  if (!fromCLI){
    
  puts("Enter First Number: ");
  scanf("%d", &firstNum);
  while(getchar() != '\n');

  //enter operator
  puts("Enter operator ( +, -, *, /, % )");
  op = getchar();
  while(getchar() != '\n');
    
  //enter 2nd number
  puts("Enter Second Number");
  scanf("%d", &secondNum);
  while(getchar() != '\n');     
  }
  
  switch (op){

    case '+' : result = sum(firstNum, secondNum); break;
    case '-' : result = sub(firstNum, secondNum); break;
    case '*' : result = mult(firstNum, secondNum); break;
    case '/' : {
      if(secondNum == 0){
        printf("Error : Division by Zero\n\n");
        exit(4);
        }
    }
      result = divide(firstNum, secondNum); break;
    case '%' : {
      if(secondNum == 0){
        printf("Error : Modulo by Zero\n\n");
        exit(4);
      break;
      }
      result = rem(firstNum, secondNum); break;
    }
      default : 
          printf("INVALID OPERATOR: %c", op);
          break;
        exit(4);
  }
    
  printf("\n\n%d %c %d = %d\n", firstNum, op, secondNum, result);
    return;
  }
} 

```

## foodMenu.c

```c

#include <stdio.h>
#include <stdlib.h>
#include "foodMenu.h"
#include <unistd.h>
#include <time.h>
#include <ctype.h>

int num_apples = 0;
int num_burgers = 0;
int num_corn = 0;
int num_drinks = 0;
int num_extras = 0;
int num_fries = 0;

void specialsPrompt(){
  puts("Would you like to see the specials? (y/n) ");
  char specialsInput; 
  specialsInput = getchar();
  while(getchar() != '\n');

  if(specialsInput == 'y' || specialsInput == 'Y'){
    puts ("Today's special is : Shrimp\n");
  }
}
void takeoutDelivery(){
  while(1){
  puts("Takeout or Delivery (t/d)");
  char takeoutDelivery = getchar();
  while(getchar() != '\n');

  if('t' == takeoutDelivery || 'T' == takeoutDelivery){
    puts("YOU SELECTED TAKOUT\n");
    return;
  }
  else if ('d' == takeoutDelivery || 'D' == takeoutDelivery){
    puts("YOU SELECTED DELIVERY\n");
    return;
  }
  continue;  
}
}
void displayFoodMenu(){
  puts("\n--MENU OPTIONS--");
  puts("(a) Apple (b) Burger (c) Corn (d) Drink (e) Extra (f) Fries (q) QUIT");
}
void foodMenuOrder(){
  while (1){
    displayFoodMenu();
    char foodMenuChoice = tolower(getchar());
    while(getchar() != '\n');
    
    switch (foodMenuChoice){
      case 'a' : num_apples++;
        break;
      case 'b' : num_burgers++;
        break;
      case 'c' : num_corn++;
        break;
      case 'd' : num_drinks++;
        break;
      case 'e' : num_extras++;
        break;
      case 'f' : num_fries++;
        break;
      case 'q' : return;

      default: puts("\nInvalid Entry. Please Enter Menu Choice");
      continue;
    }
  }
}
void displayReceipt(){
  printf("\n========== RECEIPT ========\n");
  puts("Ford's Restaurant");
  puts("Palomar College");

  time_t now = time(NULL);
  char *timeNow = ctime(&now);

  printf("%s\n", timeNow);
  
  int price = 1;
  if(num_apples > 0) {
      printf("Apple      x%d    $%d\n", num_apples, price);
  }
  if(num_burgers > 0) {
      printf("Burger     x%d    $%d\n", num_burgers, price);
  }
  if(num_corn > 0) {
      printf("Corn       x%d    $%d\n", num_corn, price);
  }
  if(num_drinks > 0) {
      printf("Drink      x%d    $%d\n", num_drinks, price);
  }
  if(num_extras > 0) {
      printf("Extra      x%d    $%d\n", num_extras, price);
  }
  if(num_fries > 0) {
      printf("Fries      x%d    $%d\n", num_fries, price);
  }

  printf("---------------------------\n");
  int total = num_apples + num_burgers + num_corn + num_drinks +               num_extras + num_fries;
  printf("Total      x%d    $%d\n", total, total);
  printf("===========================\n\n");
}
void foodPaymentMethod(){

  while(1){
  puts("SELECT YOUR PAYMENT METHOD");
  printf("\n");
  puts("(a) Cash");
  puts("(b) Credit/Debit");
  puts("(c) Crypto\n");

  char foodPayment;
  foodPayment = tolower(getchar());
  while(getchar() != '\n');
  
  switch(foodPayment){
    case 'a' : 
      printf("SEE CASHIER FOR CASH PAYMENT");
        break;
    case 'b' : 
      printf("\nProcessing Debit/Credit Payment\n");
      sleep(1);
      printf("\nPAYMENT ACCEPTED\n");
        break;
    case 'c' : 
      printf("\nProcessing Crypto Payment\n");
      sleep(1);
      printf("\nPAYMENT ACCEPTED");
        break;
    default: 
      printf("\nPlease Try Again\n\n");
      continue;
    }
    return;
  }
}

void foodMenu(){

  puts("\n================================");
  puts("          FOOD MENU");
  puts("================================\n");
  
  specialsPrompt();
  takeoutDelivery();
  foodMenuOrder();
  displayReceipt();
  foodPaymentMethod();
  
}

```

## guess-what.c

```c

#include <stdio.h>
#include "guess-what.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>


static int list_size;
int cli_get_list_size(){
    return list_size;
} 

static char **word_list;
char **cli_get_list(){
  return word_list;
}


void guessWhatHelp(){
  printf("\n");
  puts("Usage Info:");
  puts("./main -- help");
  puts("./main -- file [FILENAME]");
  puts("./main -- list [word1] [word2] ...");
  puts("Guess What From These Words!");
}

void play(char **word_list, int list_size){

  printf("Guess What word from these words!\n");
  for(int i = 0; i < list_size; i++){
    printf("%d-%s ", i + 1, word_list[i]);
    }

  printf("\n");

  int num_tries = 0;
  srand(time(NULL));

  int goal = rand() % list_size;
  printf("\ngoal: %d\n\n", goal);
  int choice;

  do{
    num_tries++;
    printf("Your Choice: ");
    scanf("%d", &choice);

  } while((goal != choice) && (num_tries < 3));

  if (goal != choice){
    printf("Sorry you lost!\n");
  }
  else{
    printf("\nYou Win!\n");
  }
}

int guessWhat(int argc, char *argv[],int loopDLooCLI){

  puts("\n================================");
  puts("          GUESS WHAT");
  puts("================================\n");

  //Handle argc = 1
  if(!loopDLooCLI){
    printf("\n**USE CONSOLE**\n");
    guessWhatHelp();
      exit(1);
  }

  char *dashCmd = argv[2];

  //Error Handling : Missing Dash Command
  if (argc < 3) {
      printf("\n**MISSING DASH COMMAND**\n");
      guessWhatHelp();
      exit(3);
  }

  ////Error Handling : Valid/Invalid Dash Command
  if (strcmp("--list", dashCmd) != 0 && strcmp("--file", dashCmd) != 0) {
      printf("INVALID DASH COMMAND: %s\n", dashCmd);
      puts("Options: --list  /  --file");
      guessWhatHelp();
      exit(3);
  }

  //handle --list
  if (0 == strcmp("--list",dashCmd)){

      if(argc < 5){
        int errorCode = 404;
        fprintf(stderr, "ERROR %d : Not Enough Words\n", errorCode);
        exit(1);
      }

      list_size = argc - 3;
      word_list = &argv[3]; 
  }

  //Handle --file
  if (0 == strcmp("--file",dashCmd)){

    char *fileName = argv[3];
    FILE *fruitsFile = fopen(fileName, "r");
      if(fruitsFile == NULL){
        perror("NON EXISTING FILE");
        exit(3);
      }

    char word[50];
    int count = 0;

    while(count < 6 && fscanf(fruitsFile, "%49s", word) == 1) {
        printf("%s\n", word);
        count++;
    }
    
    fclose(fruitsFile);
    return 1;    
  }

  //Play Game
  play(word_list, list_size);

  return 0;
}

```

## helloWorld.c

```c

#include <stdio.h>
#include <unistd.h>
#include "helloWorld.h"
#include "menu.h"

void helloWorld(){
  puts("\n================================");
  puts("Loading Hello World Program. . .");
  puts("================================\n");
  sleep(1);
  printf("Hello World\n");
}

```

## loop-d-loo.c

```c

#include <stdio.h>
#include <stdlib.h>
#include "loop-d-loo.h"

#define START_NUM_MIN 1
#define START_NUM_MAX 10
#define END_NUM_MIN 10
#define END_NUM_MAX 100

void loopDemoSeparation(){
  
}

void loopPromptInputs(int *startNum, int *endNum){

  while(1){
  printf("Enter Start Number from %d - %d: ", START_NUM_MIN, START_NUM_MAX);
  if(scanf("%d", startNum) != 1){
      printf("Invalid input. Please enter a number\n");
      while(getchar() != '\n');
      continue;
    }
  while(getchar() != '\n');
 
  if(*startNum < START_NUM_MIN || *startNum > START_NUM_MAX){
      printf("NUMBER NOT IN RANGE\n");
      continue;
    } 
    break;
  }

  while(1){
  printf("Enter Second Number from 10 - 100: ");
  if(scanf("%d", endNum) != 1){
    printf("Invalid input. Please enter a number:\n");
    while(getchar() != '\n');
      continue;
  }
  while(getchar() != '\n');
    
  if(*endNum < END_NUM_MIN || *endNum > END_NUM_MAX){
    printf("NUMBER NOT IN RANGE\n");
    continue;
  }
  break;
  }
}

void loop_cli_inputs(int *startNum, int *endNum, char *argv[]){

  if (argv[2] == NULL || argv[3] == NULL) {
    printf("Error: Not enough arguments for Loop-D-Loo\n");
    printf("Usage: ./main 5 <start_num> <end_num>\n");
    printf("Example: ./main 5 1 20\n");
    exit(1);
  }
  
  *startNum = atoi(argv[2]);
  *endNum = atoi(argv[3]);
  
  if(*startNum < START_NUM_MIN || *startNum > START_NUM_MAX) {
    printf("Error: Start Number must be between %d and %d\n", 
           START_NUM_MIN, START_NUM_MAX);
    exit(1);
  }
  
  if(*endNum < END_NUM_MIN || *endNum > END_NUM_MAX) {
    printf("Error: End Number must be between %d and %d\n", 
           END_NUM_MIN, END_NUM_MAX);
    exit(1);
  }
  
  if(*startNum >= *endNum) {
    printf("Error: Start Number must be less than End Number\n");
    exit(1);
  }
}

void loopDemo(int startNum, int endNum){

  //for loop
    printf("\n");
    printf("For Loop Demo: ");
    for(int i = startNum; i <= endNum; i++){
      printf("%d ", i);
    }
  
  printf("\n");
  //while loop
    printf("While Loop Demo: ");
      int j = startNum;
      while (j <= endNum){
        printf("%d ", j);
        j++;    
    }
  
  printf("\n");
  //do while loop
  j = startNum;
    printf("Do While Loop Demo: ");
      do{
        printf("%d ", j);
        j++;
      }
       while (j <= endNum);
  printf("\n");
}

void loopdloo(int fromCLI, char *argv[]){
  puts("\n================================");
  puts("          LOOP-D-LOO");
  puts("================================\n");

  int startNum, endNum;

  if(!fromCLI){
  loopPromptInputs(&startNum, &endNum);
  } else{
      loop_cli_inputs(&startNum, &endNum, argv);
  }

  loopDemo(startNum,endNum);
  
}

```

## menu.c

```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "welcome.h"
#include "helloWorld.h"
#include "milesToKilometers.h"
#include "calculator.h"
#include "foodMenu.h"
#include "loop-d-loo.h"
#include "guess-what.h"
#include "array-of-games.h"


void displayMenu(){
  
  char *menuOptions[8] = { 0 };
    menuOptions[0] = "Hello World";
    menuOptions[1] = "Miles to KMS";
    menuOptions[2] = "Calculator";
    menuOptions[3] = "Food Menu";
    menuOptions[4] = "Loop-D-Loo";
    menuOptions[5] = "Guess What";  
    menuOptions[6] = "Array of Games";
    menuOptions[7] = "EXIT PROGRAM";

  int arraySize = sizeof(menuOptions) / sizeof(menuOptions[0]);

  printf("\n===========================");
  puts("\nPLEASE SELECT A PROGRAM : \n");
  for(int i = 0; i < arraySize; i++){
    printf("(%d) - %s\n", i + 1, menuOptions[i]);
  }
  puts("===========================");

}

int menu(int argc, char *argv[]){

  //HANDLE PROMPTS
  if(argc == 1){
  while(1){
    displayMenu();
    int choice;
    if (scanf("%d", &choice) != 1) {
        printf("\nInvalid Input\n");
        exit(1);
    }
    getchar();
  
    switch (choice){
      case 1 : helloWorld(); break;
      case 2 : milesToKilometers(0,1); break;
      case 3 : calculator(0,0,0,'+'); break;
      case 4 : foodMenu(); break;
      case 5 : loopdloo(0,argv); break;
      case 6 : guessWhat(argc,argv,0); break;
      case 7 : arrayOfGames(); break; 
      case 8 : printf("GOODBYE!"); exit(2); break; 
      default: printf("INVALID CHOICE\n"); continue;
    }

      printf("\n\nRun another program (y/n)?\n");
      char menuRepeat = getchar();
      getchar();
      if(menuRepeat == 'y' || menuRepeat == 'Y'){
        continue;
        }
      else { printf("GOODBYE !"); exit(3);}
    }
  }

  //HANDLE CLI INPUT
  else if(argc >= 2){
    
    while(1){
      int choice = atoi(argv[1]);

      switch (choice){
        case 1 : helloWorld(); break;
        case 2 : {
          double miles = atof(argv[2]);
          milesToKilometers(miles,0);
            break;
        }
        case 3 : {

          if (argc < 4) {
              printf("Error: Calculator needs 3 arguments\n");
              printf("Usage: ./main 3 <number1> <operator> <number2>\n");
              printf("Example: ./main 3 5 + 3\n");
              exit(1);
          }
          
          int firstNum = atoi(argv[2]);
          int secondNum = atoi(argv[4]);
          char op = argv[3][0];

          if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%') {
              printf("Error: Invalid operator. Use +, -, *, /, or %%\n");
              printf("Type '*' to if you wish to multiply the two numbers\n");
              exit(1);
          }
          calculator(firstNum,secondNum,1,op); 
            break;
        }
        case 4 : foodMenu(); break;
        case 5 : loopdloo(1,argv); break;
        case 6 : guessWhat(argc,argv,1); break;
        case 7 : arrayOfGames(); break; 
        case 8 : printf("GOODBYE!"); exit(2); break; 
        default: printf("INVALID CHOICE\n"); break;
      }
      exit(1);
    }
  
  }
  
  return 1;
}

```

# milesToKilometers.c

```c

#include <stdio.h>
#include "milesToKilometers.h"
#define MILES_KMS_CONVERSION_FACTOR 1.60934

void milesToKilometers(double miles, int mtkCLI){

  puts("\n================================");
  puts("          MILES-TO-KMS");
  puts("================================\n");
  
  if(mtkCLI){ 
    while(1){
      puts("\nEnter Miles: ");
      if (scanf("%lf", &miles) != 1){
        printf("\nINVALID\n\n"); 
        while(getchar() != '\n');
        continue;
      }
      while(getchar() != '\n');
      double kms = (miles * MILES_KMS_CONVERSION_FACTOR);
      printf("%.1lf miles = %.2lf kilometers", miles, kms);
      return;
    }
  } else { // CLI
    double kms = (miles * MILES_KMS_CONVERSION_FACTOR);
    printf("%.1lf miles = %.2lf kilometers\n", miles, kms);
  }
}

```

#welcome.c

```c

#include <stdio.h>
#include <time.h>
#include "welcome.h"


#define NAME "Ford Culallad"
#define VERSION "1.0.0"

void welcome(int argc){
printf("===========================\n");
puts("CSCI 112 - Midterm Project");
printf("VERSION : %s\n", VERSION);
printf("Copyright (c) %s\n", NAME);

time_t now = time(NULL);
char *timeNow = ctime(&now);
printf("%s", timeNow);
printf("Argument Counter: %d\n", argc);
printf("===========================\n\n");
  
}


```

## fruits.txt

```

Apple Banana Durian Mango Orange Avocado

```