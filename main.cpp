#include <iostream>

using namespace std;

//Function List (All functions are below int main)
void OM ();                 //Opening Menu
void NMM ();                //New Main Menu
void MenuResetPosition ();  //Menu Position Reset
void MenuResetPosition2 (); //Menu Position Reset 2 (small)
void helpmenu ();           //Help Menu (To be revised or deleted)
void TemporaryAntiInfinity (); //Temporary solution to infinity scroll bug

int main()
{
    //Variables
    bool repeat = false;         //This variable controls the continuation of the whole program
    char menuselect;             //This variable allows the menu selection to work
    double result;               //Raw result data
    double result2;              //Shows results in kWh
    double result3;              //shows result in pesos (Using 9.59 per kWh which is February 2022 bill rate)
    char contin;                 //Loop after calculation that ask you if you are done or not
    bool repeattwo;              //Loop for the personalized feedback system, used to stop invalid input
    char decisionOM;             //Closes or Opens the program from starting screen
    bool screenresetOM;          //Resets screen in the event of invalid input from starting screen
    bool ToggleAM = false;      //Toggles Advance Mode on and off
    int ToggleAMC = 0;           //Detects if Advance mode is on or off
    bool mode1 = true;          //Hour Mode Selection
    bool mode2 = false;         //Power Rating Mode Selection
    bool mode3 = false;         //Number Mode Selection

    /*Two-Dimensional Array containing hours used and hourly consumption of appliances.
    Formatting is {hours used, hourly consumption, number of appliances}, hours used has a 0 default value.
    Users may change that 0*/
    double eleccon[19][3] =
    {
        {0, 80, 1},    //Fan 0
        {0, 400, 1},   //Aircon 1
        {0, 75, 1},    //Laptop charger 2
        {0, 200, 1},   //Desktop PC 3
        {0, 5, 1},     //Phone charger 4
        {0, 100, 1},   //Television 5
        {0, 30, 1},    //Light bulb 6
        {0, 20, 1},    //Wifi 7
        {0, 1200, 1},  //Microwave 8
        {0, 3400, 1},  //Dryer 9
        {0, 2250, 1},  //Washing Machine 10
        {24, 200, 1},  //Refrigerator 11
        {0, 200, 1},   //Rice cooker 12
        {0, 1300, 1},  //Air fryer 13
        {0, 3, 1},      //Laptop Cooler 14
        {0, 1500, 1},  //Electric kettle 15
        {0, 5, 1},     //Radio 16
        {0, 1100, 1},  //Toaster 16
        {0, 1000, 1}   //Steam iron 18
    };



    //Main program


    //Starting Screen
    do {

    if (screenresetOM == true){
        MenuResetPosition ();
    } else {
        //empty
    }

        OM ();
        cout << "Enter your choice";
        if (screenresetOM == true) {
            MenuResetPosition2 ();
        }

        screenresetOM = false;
        cin >> decisionOM;

            if (decisionOM == 'S' || decisionOM == 's'){
                //empty
            } else if (decisionOM == 'E' || decisionOM == 'e'){
                //empty
            } else {
                screenresetOM = true;
            }
    } while (screenresetOM == true);

    //Formal Start of the Program
    //Hour Mode
        do {
        if (decisionOM == 'S' && ToggleAM == false && mode1 == true && mode2 == false && mode3 == false || decisionOM == 's' && ToggleAM == false && mode1 == true && mode2 == false && mode3 == false)
        {
            MenuResetPosition ();
            NMM ();
            if (mode1 == true && ToggleAM == true){
                cout << "Mode: Advance Hour mode" << endl;
            } else if (mode2 == true && ToggleAM == true){
                cout << "Mode: Advance Power Rating Mode" << endl;
            } else if (mode3 == true && ToggleAM == true) {
                cout << "Mode: Advance Number Mode" << endl;
            } else if (mode1 == true) {
                cout << "Mode: Hour Mode" << endl;
            } else if (mode2 == true) {
                cout << "Mode: Power Rating Mode" << endl;
            } else if (mode3 == true) {
                cout << "Mode: Number Mode" << endl;
            }
            cout << "Enter your Choice" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cin >> menuselect;



                //switch system part 1
                switch (menuselect)
            {
                //Help Menu
                case '?':
                helpmenu ();
                repeat = true;
            break;

                //Resets All hour values placed by the user
                case 'X':
                for (int firstcount = 0; firstcount < 19; firstcount++)
            {
                eleccon[firstcount][0] = 0;
            }
                repeat = true;
                eleccon[11][0] = 24;
            break;

                case 'x':
                for (int firstcount = 0; firstcount < 19; firstcount++)
            {
                eleccon[firstcount][0] = 0;
            }
                repeat = true;
                eleccon[11][0] = 24;
            break;

                //Provides Results and Personalized Feedback
                case '=':
                result = (eleccon[0][2])*(eleccon[0][0]*eleccon[0][1]) + (eleccon[1][2])*(eleccon[1][0]*eleccon[1][1]) + (eleccon[2][2])*(eleccon[2][0]*eleccon[2][1]) + (eleccon[3][2])*(eleccon[3][0]*eleccon[3][1]) + (eleccon[4][2])*(eleccon[4][0]*eleccon[4][1]) + (eleccon[5][2])*(eleccon[5][0]*eleccon[5][1]) + (eleccon[6][2])*(eleccon[6][0]*eleccon[6][1]) + (eleccon[7][2])*(eleccon[7][0]*eleccon[7][1]) + (eleccon[8][2])*(eleccon[8][0]*eleccon[8][1]) + (eleccon[9][2])*(eleccon[9][0]*eleccon[9][1]) + (eleccon[10][2])*(eleccon[10][0]*eleccon[10][1]) + (eleccon[11][2])*(eleccon[11][0]*eleccon[11][1]) + (eleccon[12][2])*(eleccon[12][0]*eleccon[12][1]) + (eleccon[13][2])*(eleccon[13][0]*eleccon[13][1]) + (eleccon[14][2])*(eleccon[14][0]*eleccon[14][1])
                + (eleccon[15][2])*(eleccon[15][0]*eleccon[15][1]) + (eleccon[16][2])*(eleccon[16][0]*eleccon[16][1]) + (eleccon[17][2])*(eleccon[17][0]*eleccon[17][1]) + (eleccon[18][2])*(eleccon[18][0]*eleccon[18][1]);
                result2 = result / 1000;
                result3 = result2 * 9.59;
                cout << "Calculation Result: ";
                cout << result2 << " kWh or " << result3 << " Pesos " << endl;
                cout << "Keep this up and you can expect a cost of roughly " << result3 * 30 << " Pesos by the end of the month" << endl;
                cout << "" << endl;
                //Personalized Feedback system depending on result numbers


                //if power consumption is less than 10k watts feedback block
                if (result < 10000)
            {
                    cout << "Great results if its the consumption you had for a whole day!" << endl;
            }

                //If power consumption is less than 12k watts feedback block
                else if (result < 14000)
            {
                    cout << "Good results if its the consumption you had for a whole day." << endl;
            }

                //If power consumption is less than 15.5k watts feedback block
                else if (result <= 17500)
            {
                    cout << "Pretty bad results if its for a whole day." << endl;
            }
                //If power consumption is more than 15.5k watts feedback block
                else if (result > 17500)
            {
                    cout << "Terribe results, consider changing your way of using electricity." << endl;
            }
            //expanded area of the personalized feedback system
            cout << "" << endl;
            if (eleccon[1][0] > 12*eleccon[1][2] || eleccon[7][0] > 16*eleccon[7][2] || eleccon[4][0] > 11*eleccon[4][2] || eleccon[6][0] > 16*eleccon[6][2] && eleccon[6][1] < 25*eleccon[6][2] || eleccon[6][0] > 10*eleccon[6][2] && eleccon[6][1] >= 25*eleccon[6][2] || eleccon[6][0] > 7*eleccon[6][2] && eleccon[6][1] >= 55*eleccon[6][2]) {
                cout << "Additional Feedback:" << endl;
            }


            //aircon feedback
            if (eleccon[1][0] > 12*eleccon[1][2])
            {
                cout << "It looks like your using the aircon a bit too much, maybe try using an electric fan or waking up earlier?" << endl;
                cout << "" << endl;
            }

            //wifi feedback
            if (eleccon[7][0] > 16*eleccon[7][2])
            {
                cout << "Too much Wifi usage, consider turning it off when sleeping and sleeping for at least 8 hours long." << endl;
                cout << "" << endl;
            }

            //Phone charge feedback
            if (eleccon[4][0] > 11*eleccon[4][2])
            {
                cout << "Try to not overcharge your phone or use it this frequently. It's not good for your phone and overall energy consumption." << endl;
                cout << "" << endl;
            }

            //Light bulb feedbackS
            if (eleccon[6][0] > 16*eleccon[6][2] && eleccon[6][1] < 25*eleccon[6][2])
            {
                cout << "It looks like your using the lights too much, try closing them at night or when it is morning" << endl;
                cout << "" << endl;
            }

            else if (eleccon[6][0] > 10*eleccon[6][2] && eleccon[6][1] >= 25*eleccon[6][2])
            {
                cout << "You are likely using a fluoroscent bulb and your using too much power with it." << endl;
                cout << "Try using that bulb less or replace it with a LED or CFL bulb. Preferably LED" << endl;
                cout << "" << endl;
            }
            else if (eleccon[6][0] > 7*eleccon[6][2] && eleccon[6][1] >= 55*eleccon[6][2])
            {
                cout << "You are likely using a incandescent bulb and your using too much power with it." << endl;
                cout << "Try using that bulb less or replace it with a LED or CFL bulb. Preferably LED" << endl;
                cout << "" << endl;
            }







               repeattwo = true;
                while (repeattwo == true)
            {
                repeattwo = false;
                    cout << "Do you wish to continue using the program? (y/n) ";
                    cin >> contin;
                if (contin == 'y' || contin == 'Y')
            {
                    repeat = true;
            }
                else if (contin == 'n' || contin == 'N')
            {
                    cout << "Closing Program..." << endl;
                    repeat = false;
            }
                else
            {
                    cout << "Invalid Input, Please try again" << endl;
                    repeattwo = true;
            }



            }
                break;



                //switch system part 2
                //Give Hour value to fan
                    case 'E':
                    repeat = true;
                    cout << "How many hours did you use the fan? ";
                    cin >> eleccon[0][0];
                    TemporaryAntiInfinity ();
                break;

                //Give hour value to aircon
                    case 'A':
                    repeat = true;
                    cout << "How many hours did you use the Aircon? ";
                    cin >> eleccon[1][0];
                    TemporaryAntiInfinity ();
                break;

                //Give hour value to laptop charger
                    case 'L':
                    repeat = true;
                    cout << "How many hours did you use the Laptop Charger? ";
                    cin >> eleccon[2][0];
                    TemporaryAntiInfinity ();
                break;

                //Give hour value to desktop PC
                    case 'C':
                    repeat = true;
                    cout << "How many hours did you use the Desktop PC? ";
                    cin >> eleccon[3][0];
                    TemporaryAntiInfinity ();
                break;


                    case 'P':
                    repeat = true;
                    cout << "How many hours did you use the Phone Charger? ";
                    cin >> eleccon[4][0];
                    TemporaryAntiInfinity ();
                break;


                    case 'T':
                    repeat = true;
                    cout << "How many hours did you use the TV? ";
                    cin >> eleccon[5][0];
                    TemporaryAntiInfinity ();
                break;

                case '+':
                    if (ToggleAMC == 0){
                        ToggleAM = true;
                        ToggleAMC = 1;
                        repeat = true;
                    } else if (ToggleAMC == 1){
                        ToggleAM = false;
                        ToggleAMC = 0;
                        repeat = true;
                    }
                break;


                    case 'I':
                    repeat = true;
                    cout << "How many hours did you use the Light Bulb? ";
                    cin >> eleccon[6][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'R':
                    repeat = true;
                    cout << "How many hours did you use the Wifi Router? ";
                    cin >> eleccon[7][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'M':
                    repeat = true;
                    cout << "How many hours did you use the Microwave? ";
                    cin >> eleccon[8][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'W':
                    repeat = true;
                    cout << "How many hours did you use the Washing Machine? ";
                    cin >> eleccon[10][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'D':
                    repeat = true;
                    cout << "How many hours did you use the Dryer? ";
                    cin >> eleccon[9][0];
                    TemporaryAntiInfinity ();
                break;

                //new new new
                case 'F':
                    repeat = true;
                    cout << "How many hours did you use the ?" << endl;
                    cin >> eleccon[11][0];
                    TemporaryAntiInfinity ();
                break;

                case 'V':
                    repeat = true;
                    cout << "How many hours did you use the Rice Cooker?" << endl;
                    cin >> eleccon[12][0];
                    TemporaryAntiInfinity ();
                break;

                case 'Y':
                    repeat = true;
                    cout << "How many hours did you use the Air Fryer?" << endl;
                    cin >> eleccon[13][0];
                    TemporaryAntiInfinity ();
                break;

                case 'Z':
                    repeat = true;
                    cout << "How many hours did you use the Laptop Cooler?" << endl;
                    cin >> eleccon[14][0];
                    TemporaryAntiInfinity ();
                break;


                //new new new new new
                case 'U':
                    repeat = true;
                    cout << "How many hours did you use the Electric Kettle?" << endl;
                    cin >> eleccon[15][0];
                    TemporaryAntiInfinity ();
                break;

                case 'Q':
                    repeat = true;
                    cout << "How many hours did you use the Radio?" << endl;
                    cin >> eleccon[16][0];
                    TemporaryAntiInfinity ();
                break;

                case 'O':
                    repeat = true;
                    cout << "How many hours did you use the Toaster?" << endl;
                    cin >> eleccon[17][0];
                    TemporaryAntiInfinity ();
                break;

                case 'S':
                    repeat = true;
                    cout << "How many hours did you use the Steam Iron?" << endl;
                    cin >> eleccon[18][0];
                    TemporaryAntiInfinity ();
                break;


                    case 'H':
                        mode1 = true;
                        mode2 = false;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'J':
                        mode1 = false;
                        mode2 = true;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'K':
                        mode1 = false;
                        mode2 = false;
                        mode3 = true;
                        repeat = true;
                    break;

// break



                //new new new new new
                case 'u':
                    repeat = true;
                    cout << "How many hours did you use the Electric Kettle?" << endl;
                    cin >> eleccon[15][0];
                    TemporaryAntiInfinity ();
                break;

                case 'q':
                    repeat = true;
                    cout << "How many hours did you use the Radio?" << endl;
                    cin >> eleccon[16][0];
                    TemporaryAntiInfinity ();
                break;

                case 'o':
                    repeat = true;
                    cout << "How many hours did you use the Toaster?" << endl;
                    cin >> eleccon[17][0];
                    TemporaryAntiInfinity ();
                break;

                case 's':
                    repeat = true;
                    cout << "How many hours did you use the Steam Iron?" << endl;
                    cin >> eleccon[18][0];
                    TemporaryAntiInfinity ();
                break;


                    case 'e':
                    repeat = true;
                    cout << "How many hours did you use the fan? ";
                    cin >> eleccon[0][0];
                    TemporaryAntiInfinity ();
                break;

                //Give hour value to aircon
                    case 'a':
                    repeat = true;
                    cout << "How many hours did you use the Aircon? ";
                    cin >> eleccon[1][0];
                    TemporaryAntiInfinity ();
                break;

                //Give hour value to laptop charger
                    case 'l':
                    repeat = true;
                    cout << "How many hours did you use the Laptop Charger? ";
                    cin >> eleccon[2][0];
                    TemporaryAntiInfinity ();
                break;

                //Give hour value to desktop PC
                    case 'c':
                    repeat = true;
                    cout << "How many hours did you use the Desktop PC? ";
                    cin >> eleccon[3][0];
                    TemporaryAntiInfinity ();
                break;


                    case 'p':
                    repeat = true;
                    cout << "How many hours did you use the Phone Charger? ";
                    cin >> eleccon[4][0];
                    TemporaryAntiInfinity ();
                break;


                    case 't':
                    repeat = true;
                    cout << "How many hours did you use the TV? ";
                    cin >> eleccon[5][0];
                    TemporaryAntiInfinity ();
                break;


                    case 'i':
                    repeat = true;
                    cout << "How many hours did you use the Light Bulb? ";
                    cin >> eleccon[6][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'r':
                    repeat = true;
                    cout << "How many hours did you use the Wifi Router? ";
                    cin >> eleccon[7][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'm':
                    repeat = true;
                    cout << "How many hours did you use the Microwave? ";
                    cin >> eleccon[8][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'w':
                    repeat = true;
                    cout << "How many hours did you use the Washing Machine? ";
                    cin >> eleccon[10][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'd':
                    repeat = true;
                    cout << "How many hours did you use the Dryer? ";
                    cin >> eleccon[9][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'h':
                        mode1 = true;
                        mode2 = false;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'j':
                        mode1 = false;
                        mode2 = true;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'k':
                        mode1 = false;
                        mode2 = false;
                        mode3 = true;
                        repeat = true;
                    break;

                //new new new
                case 'f':
                    repeat = true;
                    cout << "How many hours did you use the Fridge?" << endl;
                    cin >> eleccon[11][0];
                    TemporaryAntiInfinity ();
                break;

                case 'v':
                    repeat = true;
                    cout << "How many hours did you use the Rice Cooker?" << endl;
                    cin >> eleccon[12][0];
                    TemporaryAntiInfinity ();
                break;

                case 'y':
                    repeat = true;
                    cout << "How many hours did you use the Air Fryer?" << endl;
                    cin >> eleccon[13][0];
                    TemporaryAntiInfinity ();
                break;

                case 'z':
                    repeat = true;
                    cout << "How many hours did you use the Laptop Cooler?" << endl;
                    cin >> eleccon[14][0];
                    TemporaryAntiInfinity ();
                break;



                    default:
                    repeat = true;
                    cout << "INVALID INPUT, PLEASE TRY AGAIN" << endl;
                };

                }



        //Power Rating Mode
        else if (decisionOM == 'S' && ToggleAM == false && mode1 == false && mode2 == true && mode3 == false || decisionOM == 's' && ToggleAM == false && mode1 == false && mode2 == true && mode3 == false)
        {
            MenuResetPosition ();
            NMM ();
            if (mode1 == true && ToggleAM == true){
                cout << "Mode: Advance Hour mode" << endl;
            } else if (mode2 == true && ToggleAM == true){
                cout << "Mode: Advance Power Rating Mode" << endl;
            } else if (mode3 == true && ToggleAM == true) {
                cout << "Mode: Advance Number Mode" << endl;
            } else if (mode1 == true) {
                cout << "Mode: Hour Mode" << endl;
            } else if (mode2 == true) {
                cout << "Mode: Power Rating Mode" << endl;
            } else if (mode3 == true) {
                cout << "Mode: Number Mode" << endl;
            }
            cout << "Enter your Choice" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cin >> menuselect;



                //switch system part 1
                switch (menuselect)
            {
                //Help Menu
                case '?':
                helpmenu ();
                repeat = true;
            break;


                //Resets All power rating values placed by the user
                case 'X':
                eleccon[0][1] = 80;
                eleccon[1][1] = 650;
                eleccon[2][1] = 75;
                eleccon[3][1] = 200;
                eleccon[4][1] = 5;
                eleccon[5][1] = 100;
                eleccon[6][1] = 30;
                eleccon[7][1] = 20;
                eleccon[8][1] = 1200;
                eleccon[9][1] = 3400;
                eleccon[10][1] = 2250;
                eleccon[11][1] = 565;
                eleccon[12][1] = 200;
                eleccon[13][1] = 1300;
                eleccon[14][1] = 3;
                eleccon[15][1] = 1500;
                eleccon[16][1] = 5;
                eleccon[17][1] = 1100;
                eleccon[18][1] = 1000;
                repeat = true;
            break;

                case 'x':
                eleccon[0][1] = 80;
                eleccon[1][1] = 650;
                eleccon[2][1] = 75;
                eleccon[3][1] = 200;
                eleccon[4][1] = 5;
                eleccon[5][1] = 100;
                eleccon[6][1] = 30;
                eleccon[7][1] = 20;
                eleccon[8][1] = 1200;
                eleccon[9][1] = 3400;
                eleccon[10][1] = 2250;
                eleccon[11][1] = 565;
                eleccon[12][1] = 200;
                eleccon[13][1] = 1300;
                eleccon[14][1] = 3;
                eleccon[15][1] = 1500;
                eleccon[16][1] = 5;
                eleccon[17][1] = 1100;
                eleccon[18][1] = 1000;
                repeat = true;
            break;

                //Provides Results and Personalized Feedback
                case '=':
                result = (eleccon[0][2])*(eleccon[0][0]*eleccon[0][1]) + (eleccon[1][2])*(eleccon[1][0]*eleccon[1][1]) + (eleccon[2][2])*(eleccon[2][0]*eleccon[2][1]) + (eleccon[3][2])*(eleccon[3][0]*eleccon[3][1]) + (eleccon[4][2])*(eleccon[4][0]*eleccon[4][1]) + (eleccon[5][2])*(eleccon[5][0]*eleccon[5][1]) + (eleccon[6][2])*(eleccon[6][0]*eleccon[6][1]) + (eleccon[7][2])*(eleccon[7][0]*eleccon[7][1]) + (eleccon[8][2])*(eleccon[8][0]*eleccon[8][1]) + (eleccon[9][2])*(eleccon[9][0]*eleccon[9][1]) + (eleccon[10][2])*(eleccon[10][0]*eleccon[10][1]) + (eleccon[11][2])*(eleccon[11][0]*eleccon[11][1]) + (eleccon[12][2])*(eleccon[12][0]*eleccon[12][1]) + (eleccon[13][2])*(eleccon[13][0]*eleccon[13][1]) + (eleccon[14][2])*(eleccon[14][0]*eleccon[14][1])
                + (eleccon[15][2])*(eleccon[15][0]*eleccon[15][1]) + (eleccon[16][2])*(eleccon[16][0]*eleccon[16][1]) + (eleccon[17][2])*(eleccon[17][0]*eleccon[17][1]) + (eleccon[18][2])*(eleccon[18][0]*eleccon[18][1]);
                result2 = result / 1000;
                result3 = result2 * 9.59;
                cout << "Calculation Result: ";
                cout << result2 << " kWh or " << result3 << " Pesos " << endl;
                cout << "Keep this up and you can expect a cost of roughly " << result3 * 30 << " Pesos by the end of the month" << endl;
                cout << "" << endl;
                //Personalized Feedback system depending on result numbers


                //if power consumption is less than 10k watts feedback block
                if (result < 10000)
            {
                    cout << "Great results if its the consumption you had for a whole day!" << endl;
            }

                //If power consumption is less than 12k watts feedback block
                else if (result < 14000)
            {
                    cout << "Good results if its the consumption you had for a whole day." << endl;
            }

                //If power consumption is less than 15.5k watts feedback block
                else if (result <= 17500)
            {
                    cout << "Pretty bad results if its for a whole day." << endl;
            }
                //If power consumption is more than 15.5k watts feedback block
                else if (result > 17500)
            {
                    cout << "Terribe results, consider changing your way of using electricity." << endl;
            }
            //expanded area of the personalized feedback system
            cout << "" << endl;
            if (eleccon[1][0] > 12*eleccon[1][2] || eleccon[7][0] > 16*eleccon[7][2] || eleccon[4][0] > 11*eleccon[4][2] || eleccon[6][0] > 16*eleccon[6][2] && eleccon[6][1] < 25*eleccon[6][2] || eleccon[6][0] > 10*eleccon[6][2] && eleccon[6][1] >= 25*eleccon[6][2] || eleccon[6][0] > 7*eleccon[6][2] && eleccon[6][1] >= 55*eleccon[6][2]) {
                cout << "Additional Feedback:" << endl;
            }


            //aircon feedback
            if (eleccon[1][0] > 12*eleccon[1][2])
            {
                cout << "It looks like your using the aircon a bit too much, maybe try using an electric fan or waking up earlier?" << endl;
                cout << "" << endl;
            }

            //wifi feedback
            if (eleccon[7][0] > 16*eleccon[7][2])
            {
                cout << "Too much Wifi usage, consider turning it off when sleeping and sleeping for at least 8 hours long." << endl;
                cout << "" << endl;
            }

            //Phone charge feedback
            if (eleccon[4][0] > 11*eleccon[4][2])
            {
                cout << "Try to not overcharge your phone or use it this frequently. It's not good for your phone and overall energy consumption." << endl;
                cout << "" << endl;
            }

            //Light bulb feedbackS
            if (eleccon[6][0] > 16*eleccon[6][2] && eleccon[6][1] < 25*eleccon[6][2])
            {
                cout << "It looks like your using the lights too much, try closing them at night or when it is morning" << endl;
                cout << "" << endl;
            }

            else if (eleccon[6][0] > 10*eleccon[6][2] && eleccon[6][1] >= 25*eleccon[6][2])
            {
                cout << "You are likely using a fluoroscent bulb and your using too much power with it." << endl;
                cout << "Try using that bulb less or replace it with a LED or CFL bulb. Preferably LED" << endl;
                cout << "" << endl;
            }
            else if (eleccon[6][0] > 7*eleccon[6][2] && eleccon[6][1] >= 55*eleccon[6][2])
            {
                cout << "You are likely using a incandescent bulb and your using too much power with it." << endl;
                cout << "Try using that bulb less or replace it with a LED or CFL bulb. Preferably LED" << endl;
                cout << "" << endl;
            }








               repeattwo = true;
                while (repeattwo == true)
            {
                repeattwo = false;
                    cout << "Do you wish to continue using the program? (y/n) ";
                    cin >> contin;
                if (contin == 'y' || contin == 'Y')
            {
                    repeat = true;
            }
                else if (contin == 'n' || contin == 'N')
            {
                    cout << "Closing Program..." << endl;
                    repeat = false;
            }
                else
            {
                    cout << "Invalid Input, Please try again" << endl;
                    repeattwo = true;
            }



            }
                break;



                //switch system part 2
                //Give power rating value for fan
                //new new new new new
                case 'U':
                    repeat = true;
                    cout << "What is your Electric Kettle power rating?" << endl;
                    cin >> eleccon[15][1];
                    TemporaryAntiInfinity ();
                break;

                case 'Q':
                    repeat = true;
                    cout << "What is your Radio power rating?" << endl;
                    cin >> eleccon[16][1];
                    TemporaryAntiInfinity ();
                break;

                case 'O':
                    repeat = true;
                    cout << "What is your Toaster power rating?" << endl;
                    cin >> eleccon[17][1];
                    TemporaryAntiInfinity ();
                break;

                case 'S':
                    repeat = true;
                    cout << "What is your Steam Iron power rating?" << endl;
                    cin >> eleccon[18][1];
                    TemporaryAntiInfinity ();
                break;

                case 'u':
                    repeat = true;
                    cout << "What is your Electric Kettle power rating?" << endl;
                    cin >> eleccon[15][1];
                    TemporaryAntiInfinity ();
                break;

                case 'q':
                    repeat = true;
                    cout << "What is your Radio power rating?" << endl;
                    cin >> eleccon[16][1];
                    TemporaryAntiInfinity ();
                break;

                case 'o':
                    repeat = true;
                    cout << "What is your Toaster power rating?" << endl;
                    cin >> eleccon[17][1];
                    TemporaryAntiInfinity ();
                break;

                case 's':
                    repeat = true;
                    cout << "What is your Steam Iron power rating?" << endl;
                    cin >> eleccon[18][1];
                    TemporaryAntiInfinity ();
                break;



                    case 'E':
                    repeat = true;
                    cout << "What is your fan power rating? ";
                    cin >> eleccon[0][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating value for aircon
                    case 'A':
                    repeat = true;
                    cout << "What is your aircon power rating? ";
                    cin >> eleccon[1][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating value for laptop charger
                    case 'L':
                    repeat = true;
                    cout << "What is your laptop charger power rating? ";
                    cin >> eleccon[2][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating value for desktop PC
                    case 'C':
                    repeat = true;
                    cout << "What is your desktop computer power rating? ";
                    cin >> eleccon[3][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating value for phone charger
                    case 'P':
                    repeat = true;
                    cout << "What is your phone charger power rating? ";
                    cin >> eleccon[4][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating for TV
                    case 'T':
                    repeat = true;
                    cout << "What is your TV power rating? ";
                    cin >> eleccon[5][1];
                    TemporaryAntiInfinity ();
                break;

                case '+':
                    if (ToggleAMC == 0){
                        ToggleAM = true;
                        ToggleAMC = 1;
                        repeat = true;
                    } else if (ToggleAMC == 1){
                        ToggleAM = false;
                        ToggleAMC = 0;
                        repeat = true;
                    }
                break;

                //Give power rating for light bulb
                    case 'I':
                    repeat = true;
                    cout << "What is your light bulb power rating? ";
                    cin >> eleccon[6][1];
                    TemporaryAntiInfinity ();
                break;
                //Give power rating for wifi router
                    case 'R':
                    repeat = true;
                    cout << "What is your wifi router power rating? ";
                    cin >> eleccon[7][1];
                    TemporaryAntiInfinity ();
                break;
                //Give power rating for microwave
                    case 'M':
                    repeat = true;
                    cout << "What is your microwave power rating? ";
                    cin >> eleccon[8][1];
                    TemporaryAntiInfinity ();
                break;
                //Give power rating for washing machine
                    case 'W':
                    repeat = true;
                    cout << "What is your washing machine power rating? ";
                    cin >> eleccon[10][1];
                    TemporaryAntiInfinity ();
                break;
                //Give power rating for Dryer
                    case 'D':
                    repeat = true;
                    cout << "What is your dryer power rating? ";
                    cin >> eleccon[9][1];
                    TemporaryAntiInfinity ();
                break;
                    case 'H':
                        mode1 = true;
                        mode2 = false;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'J':
                        mode1 = false;
                        mode2 = true;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'K':
                        mode1 = false;
                        mode2 = false;
                        mode3 = true;
                        repeat = true;
                    break;

                //new new new
                case 'F':
                    repeat = true;
                    cout << "What is your Fridge power rating?" << endl;
                    cin >> eleccon[11][1];
                    TemporaryAntiInfinity ();
                break;

                case 'V':
                    repeat = true;
                    cout << "What is your Rice Cooker power rating?" << endl;
                    cin >> eleccon[12][1];
                    TemporaryAntiInfinity ();
                break;

                case 'Y':
                    repeat = true;
                    cout << "What is your Air Fryer power rating?" << endl;
                    cin >> eleccon[13][1];
                    TemporaryAntiInfinity ();
                break;

                case 'Z':
                    repeat = true;
                    cout << "What is your Laptop Cooler power rating?" << endl;
                    cin >> eleccon[14][1];
                    TemporaryAntiInfinity ();
                break;



//break  s
                    case 'e':
                    repeat = true;
                    cout << "What is your fan power rating? ";
                    cin >> eleccon[0][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating value for aircon
                    case 'a':
                    repeat = true;
                    cout << "What is your aircon power rating? ";
                    cin >> eleccon[1][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating value for laptop charger
                    case 'l':
                    repeat = true;
                    cout << "What is your laptop charger power rating? ";
                    cin >> eleccon[2][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating value for desktop PC
                    case 'c':
                    repeat = true;
                    cout << "What is your desktop computer power rating? ";
                    cin >> eleccon[3][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating value for phone charger
                    case 'p':
                    repeat = true;
                    cout << "What is your phone charger power rating? ";
                    cin >> eleccon[4][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating for TV
                    case 't':
                    repeat = true;
                    cout << "What is your TV power rating? ";
                    cin >> eleccon[5][1];
                    TemporaryAntiInfinity ();
                break;


                //Give power rating for light bulb
                    case 'i':
                    repeat = true;
                    cout << "What is your light bulb power rating? ";
                    cin >> eleccon[6][1];
                    TemporaryAntiInfinity ();
                break;
                //Give power rating for wifi router
                    case 'r':
                    repeat = true;
                    cout << "What is your wifi router power rating? ";
                    cin >> eleccon[7][1];
                    TemporaryAntiInfinity ();
                break;
                //Give power rating for microwave
                    case 'm':
                    repeat = true;
                    cout << "What is your microwave power rating? ";
                    cin >> eleccon[8][1];
                    TemporaryAntiInfinity ();
                break;
                //Give power rating for washing machine
                    case 'w':
                    repeat = true;
                    cout << "What is your washing machine power rating? ";
                    cin >> eleccon[10][1];
                    TemporaryAntiInfinity ();
                break;
                //Give power rating for Dryer
                    case 'd':
                    repeat = true;
                    cout << "What is your dryer power rating? ";
                    cin >> eleccon[9][1];
                    TemporaryAntiInfinity ();
                break;
                    case 'h':
                        mode1 = true;
                        mode2 = false;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'j':
                        mode1 = false;
                        mode2 = true;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'k':
                        mode1 = false;
                        mode2 = false;
                        mode3 = true;
                        repeat = true;
                    break;



                //new new new
                case 'f':
                    repeat = true;
                    cout << "What is your Fridge power rating?" << endl;
                    cin >> eleccon[11][1];
                    TemporaryAntiInfinity ();
                break;

                case 'v':
                    repeat = true;
                    cout << "What is your Rice Cooker power rating?" << endl;
                    cin >> eleccon[12][1];
                    TemporaryAntiInfinity ();
                break;

                case 'y':
                    repeat = true;
                    cout << "What is your Air Fryer power rating?" << endl;
                    cin >> eleccon[13][1];
                    TemporaryAntiInfinity ();
                break;

                case 'z':
                    repeat = true;
                    cout << "What is your Laptop Cooler power rating?" << endl;
                    cin >> eleccon[14][1];
                    TemporaryAntiInfinity ();
                break;


                    default:
                    repeat = true;
                    cout << "INVALID INPUT, PLEASE TRY AGAIN" << endl;
                };

                }





        //Number Mode
        else if (decisionOM == 'S' && ToggleAM == false && mode1 == false && mode2 == false && mode3 == true || decisionOM == 's' && ToggleAM == false && mode1 == false && mode2 == false && mode3 == true)
        {
            MenuResetPosition ();
            NMM ();
            if (mode1 == true && ToggleAM == true){
                cout << "Mode: Advance Hour mode" << endl;
            } else if (mode2 == true && ToggleAM == true){
                cout << "Mode: Advance Power Rating Mode" << endl;
            } else if (mode3 == true && ToggleAM == true) {
                cout << "Mode: Advance Number Mode" << endl;
            } else if (mode1 == true) {
                cout << "Mode: Hour Mode" << endl;
            } else if (mode2 == true) {
                cout << "Mode: Power Rating Mode" << endl;
            } else if (mode3 == true) {
                cout << "Mode: Number Mode" << endl;
            }
            cout << "Enter your Choice" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cin >> menuselect;



                //switch system part 1
                switch (menuselect)
            {
                //Help Menu
                case '?':
                helpmenu ();
                repeat = true;
            break;

                //Resets All Number values to 1
                case 'X':
                for (int firstcount = 0; firstcount < 19; firstcount++)
            {
                eleccon[firstcount][2] = 1;
            }
                repeat = true;
            break;

                case 'x':
                for (int firstcount = 0; firstcount < 19; firstcount++)
            {
                eleccon[firstcount][2] = 1;
            }
                repeat = true;
            break;

                //Provides Results and Personalized Feedback
                case '=':
                result = (eleccon[0][2])*(eleccon[0][0]*eleccon[0][1]) + (eleccon[1][2])*(eleccon[1][0]*eleccon[1][1]) + (eleccon[2][2])*(eleccon[2][0]*eleccon[2][1]) + (eleccon[3][2])*(eleccon[3][0]*eleccon[3][1]) + (eleccon[4][2])*(eleccon[4][0]*eleccon[4][1]) + (eleccon[5][2])*(eleccon[5][0]*eleccon[5][1]) + (eleccon[6][2])*(eleccon[6][0]*eleccon[6][1]) + (eleccon[7][2])*(eleccon[7][0]*eleccon[7][1]) + (eleccon[8][2])*(eleccon[8][0]*eleccon[8][1]) + (eleccon[9][2])*(eleccon[9][0]*eleccon[9][1]) + (eleccon[10][2])*(eleccon[10][0]*eleccon[10][1]) + (eleccon[11][2])*(eleccon[11][0]*eleccon[11][1]) + (eleccon[12][2])*(eleccon[12][0]*eleccon[12][1]) + (eleccon[13][2])*(eleccon[13][0]*eleccon[13][1]) + (eleccon[14][2])*(eleccon[14][0]*eleccon[14][1])
                + (eleccon[15][2])*(eleccon[15][0]*eleccon[15][1]) + (eleccon[16][2])*(eleccon[16][0]*eleccon[16][1]) + (eleccon[17][2])*(eleccon[17][0]*eleccon[17][1]) + (eleccon[18][2])*(eleccon[18][0]*eleccon[18][1]);
                result2 = result / 1000;
                result3 = result2 * 9.59;
                cout << "Calculation Result: ";
                cout << result2 << " kWh or " << result3 << " Pesos " << endl;
                cout << "Keep this up and you can expect a cost of roughly " << result3 * 30 << " Pesos by the end of the month" << endl;
                cout << "" << endl;
                //Personalized Feedback system depending on result numbers


                //if power consumption is less than 10k watts feedback block
                if (result < 10000)
            {
                    cout << "Great results if its the consumption you had for a whole day!" << endl;
            }

                //If power consumption is less than 12k watts feedback block
                else if (result < 14000)
            {
                    cout << "Good results if its the consumption you had for a whole day." << endl;
            }

                //If power consumption is less than 15.5k watts feedback block
                else if (result <= 17500)
            {
                    cout << "Pretty bad results if its for a whole day." << endl;
            }
                //If power consumption is more than 15.5k watts feedback block
                else if (result > 17500)
            {
                    cout << "Terribe results, consider changing your way of using electricity." << endl;
            }
            //expanded area of the personalized feedback system
            cout << "" << endl;
            if (eleccon[1][0] > 12*eleccon[1][2] || eleccon[7][0] > 16*eleccon[7][2] || eleccon[4][0] > 11*eleccon[4][2] || eleccon[6][0] > 16*eleccon[6][2] && eleccon[6][1] < 25*eleccon[6][2] || eleccon[6][0] > 10*eleccon[6][2] && eleccon[6][1] >= 25*eleccon[6][2] || eleccon[6][0] > 7*eleccon[6][2] && eleccon[6][1] >= 55*eleccon[6][2]) {
                cout << "Additional Feedback:" << endl;
            }

            //aircon feedback
            if (eleccon[1][0] > 12*eleccon[1][2])
            {
                cout << "It looks like your using the aircon a bit too much, maybe try using an electric fan or waking up earlier?" << endl;
                cout << "" << endl;
            }

            //wifi feedback
            if (eleccon[7][0] > 16*eleccon[7][2])
            {
                cout << "Too much Wifi usage, consider turning it off when sleeping and sleeping for at least 8 hours long." << endl;
                cout << "" << endl;
            }

            //Phone charge feedback
            if (eleccon[4][0] > 11*eleccon[4][2])
            {
                cout << "Try to not overcharge your phone or use it this frequently. It's not good for your phone and overall energy consumption." << endl;
                cout << "" << endl;
            }

            //Light bulb feedbackS
            if (eleccon[6][0] > 16*eleccon[6][2] && eleccon[6][1] < 25*eleccon[6][2])
            {
                cout << "It looks like your using the lights too much, try closing them at night or when it is morning" << endl;
                cout << "" << endl;
            }

            else if (eleccon[6][0] > 10*eleccon[6][2] && eleccon[6][1] >= 25*eleccon[6][2])
            {
                cout << "You are likely using a fluoroscent bulb and your using too much power with it." << endl;
                cout << "Try using that bulb less or replace it with a LED or CFL bulb. Preferably LED" << endl;
                cout << "" << endl;
            }
            else if (eleccon[6][0] > 7*eleccon[6][2] && eleccon[6][1] >= 55*eleccon[6][2])
            {
                cout << "You are likely using a incandescent bulb and your using too much power with it." << endl;
                cout << "Try using that bulb less or replace it with a LED or CFL bulb. Preferably LED" << endl;
                cout << "" << endl;
            }








               repeattwo = true;
                while (repeattwo == true)
            {
                repeattwo = false;
                    cout << "Do you wish to continue using the program? (y/n) ";
                    cin >> contin;
                if (contin == 'y' || contin == 'Y')
            {
                    repeat = true;
            }
                else if (contin == 'n' || contin == 'N')
            {
                    cout << "Closing Program..." << endl;
                    repeat = false;
            }
                else
            {
                    cout << "Invalid Input, Please try again" << endl;
                    repeattwo = true;
            }



            }
                break;



                //switch system part 2
                //Give number of fans

                case 'U':
                    repeat = true;
                    cout << "How many Electric Kettles do you have?" << endl;
                    cin >> eleccon[15][2];
                    TemporaryAntiInfinity ();
                break;

                case 'Q':
                    repeat = true;
                    cout << "How many Radios do you have?" << endl;
                    cin >> eleccon[16][2];
                    TemporaryAntiInfinity ();
                break;

                case 'O':
                    repeat = true;
                    cout << "How many Toasters do you have?" << endl;
                    cin >> eleccon[17][2];
                    TemporaryAntiInfinity ();
                break;

                case 'S':
                    repeat = true;
                    cout << "How many Steam Irons do you have?" << endl;
                    cin >> eleccon[18][2];
                    TemporaryAntiInfinity ();
                break;

                case 'u':
                    repeat = true;
                    cout << "How many Electric Kettles do you have?" << endl;
                    cin >> eleccon[15][2];
                    TemporaryAntiInfinity ();
                break;

                case 'q':
                    repeat = true;
                    cout << "How many Radios do you have?" << endl;
                    cin >> eleccon[16][2];
                    TemporaryAntiInfinity ();
                break;

                case 'o':
                    repeat = true;
                    cout << "How many Toasters do you have?" << endl;
                    cin >> eleccon[17][2];
                    TemporaryAntiInfinity ();
                break;

                case 's':
                    repeat = true;
                    cout << "How many Steam Irons do you have?" << endl;
                    cin >> eleccon[18][2];
                    TemporaryAntiInfinity ();
                break;

                    case 'E':
                    repeat = true;
                    cout << "How many fans do you have? ";
                    cin >> eleccon[0][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of aircons
                    case 'A':
                    repeat = true;
                    cout << "How many aircons do you have? ";
                    cin >> eleccon[1][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of laptop chargers
                    case 'L':
                    repeat = true;
                    cout << "How many laptop chargers do you have? ";
                    cin >> eleccon[2][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of desktop PC
                    case 'C':
                    repeat = true;
                    cout << "How many desktop PCs do you have? ";
                    cin >> eleccon[3][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of phone chargers
                    case 'P':
                    repeat = true;
                    cout << "How many phone chargers do you have? ";
                    cin >> eleccon[4][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of TVs
                    case 'T':
                    repeat = true;
                    cout << "How many TVs do you have? ";
                    cin >> eleccon[5][2];
                    TemporaryAntiInfinity ();
                break;

                case '+':
                    if (ToggleAMC == 0){
                        ToggleAM = true;
                        ToggleAMC = 1;
                        repeat = true;
                    } else if (ToggleAMC == 1){
                        ToggleAM = false;
                        ToggleAMC = 0;
                        repeat = true;
                    }
                break;

                //Give number of light bulbs
                    case 'I':
                    repeat = true;
                    cout << "How many light bulbs do you have? ";
                    cin >> eleccon[6][2];
                    TemporaryAntiInfinity ();
                break;
                //Give number of wifi routers
                    case 'R':
                    repeat = true;
                    cout << "How many wifi routers do you have? ";
                    cin >> eleccon[7][2];
                    TemporaryAntiInfinity ();
                break;
                //Give number of microwaves
                    case 'M':
                    repeat = true;
                    cout << "How many microwaves do you have? ";
                    cin >> eleccon[8][2];
                    TemporaryAntiInfinity ();
                break;
                //Give number of washing machines
                    case 'W':
                    repeat = true;
                    cout << "How many washing machines do you have? ";
                    cin >> eleccon[10][2];
                    TemporaryAntiInfinity ();
                break;
                //Give number of dryers
                    case 'D':
                    repeat = true;
                    cout << "How many dryers do you have? ";
                    cin >> eleccon[9][2];
                    TemporaryAntiInfinity ();
                break;
                    case 'H':
                        mode1 = true;
                        mode2 = false;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'J':
                        mode1 = false;
                        mode2 = true;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'K':
                        mode1 = false;
                        mode2 = false;
                        mode3 = true;
                        repeat = true;
                    break;


                    //new new new new
                case 'F':
                    repeat = true;
                    cout << "How many Fridges do you have?" << endl;
                    cin >> eleccon[11][2];
                    TemporaryAntiInfinity ();
                break;

                case 'V':
                    repeat = true;
                    cout << "How many Rice Cookers do you have?" << endl;
                    cin >> eleccon[12][2];
                    TemporaryAntiInfinity ();
                break;

                case 'Y':
                    repeat = true;
                    cout << "How many Air Fryers do you have?" << endl;
                    cin >> eleccon[13][2];
                    TemporaryAntiInfinity ();
                break;

                case 'Z':
                    repeat = true;
                    cout << "How many Laptop Coolers do you have?" << endl;
                    cin >> eleccon[14][2];
                    TemporaryAntiInfinity ();
                break;





//break s s
                    case 'e':
                    repeat = true;
                    cout << "How many fans do you have? ";
                    cin >> eleccon[0][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of aircons
                    case 'a':
                    repeat = true;
                    cout << "How many aircons do you have? ";
                    cin >> eleccon[1][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of laptop chargers
                    case 'l':
                    repeat = true;
                    cout << "How many laptop chargers do you have? ";
                    cin >> eleccon[2][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of desktop PC
                    case 'c':
                    repeat = true;
                    cout << "How many desktop PCs do you have? ";
                    cin >> eleccon[3][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of phone chargers
                    case 'p':
                    repeat = true;
                    cout << "How many phone chargers do you have? ";
                    cin >> eleccon[4][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of TVs
                    case 't':
                    repeat = true;
                    cout << "How many TVs do you have? ";
                    cin >> eleccon[5][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of light bulbs
                    case 'i':
                    repeat = true;
                    cout << "How many light bulbs do you have? ";
                    cin >> eleccon[6][2];
                    TemporaryAntiInfinity ();
                break;
                //Give number of wifi routers
                    case 'r':
                    repeat = true;
                    cout << "How many wifi routers do you have? ";
                    cin >> eleccon[7][2];
                    TemporaryAntiInfinity ();
                break;
                //Give number of microwaves
                    case 'm':
                    repeat = true;
                    cout << "How many microwaves do you have? ";
                    cin >> eleccon[8][2];
                    TemporaryAntiInfinity ();
                break;
                //Give number of washing machines
                    case 'w':
                    repeat = true;
                    cout << "How many washing machines do you have? ";
                    cin >> eleccon[10][2];
                    TemporaryAntiInfinity ();
                break;
                //Give number of dryers
                    case 'd':
                    repeat = true;
                    cout << "How many dryers do you have? ";
                    cin >> eleccon[9][2];
                    TemporaryAntiInfinity ();
                break;
                    case 'h':
                        mode1 = true;
                        mode2 = false;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'j':
                        mode1 = false;
                        mode2 = true;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'k':
                        mode1 = false;
                        mode2 = false;
                        mode3 = true;
                        repeat = true;
                    break;


                    //new new new new
                case 'f':
                    repeat = true;
                    cout << "How many Fridges do you have?" << endl;
                    cin >> eleccon[11][2];
                    TemporaryAntiInfinity ();
                break;

                case 'v':
                    repeat = true;
                    cout << "How many Rice Cookers do you have?" << endl;
                    cin >> eleccon[12][2];
                    TemporaryAntiInfinity ();
                break;

                case 'y':
                    repeat = true;
                    cout << "How many Air Fryers do you have?" << endl;
                    cin >> eleccon[13][2];
                    TemporaryAntiInfinity ();
                break;

                case 'z':
                    repeat = true;
                    cout << "How many Laptop Coolers do you have?" << endl;
                    cin >> eleccon[14][2];
                    TemporaryAntiInfinity ();
                break;

                    default:
                    repeat = true;
                    cout << "INVALID INPUT, PLEASE TRY AGAIN" << endl;
                };

                }






        //Start of Hour Advance Mode interface
        //Advance hour mode
        else if (ToggleAM == true && mode1 == true) {
            MenuResetPosition ();

    cout << "**************************************************************************************************************" <<endl;
    cout << "*                                                                                                            *" <<endl;
    cout << "*                                     Energy Consumption Feedback Program                                    *" <<endl;
    cout << "*                                                                                                            *" <<endl;
    cout << "**************************************************************************************************************" <<endl;
    cout << endl;
    cout << "     Special Commands:" << endl;
    cout << "     = - Calculate                      X - Clear all input                  + - Advance Mode" << endl;
    cout << "     H - Toggle Hours Mode              J - Toggle Power Rating Mode         K - Toggle Number Mode" << endl;
    cout << "     ? - Help Menu" << endl;
    cout << endl;
    cout << "     Appliances:" << endl;
    cout << "     E - Electric Fan ("<< eleccon[0][0] <<","<<" " << eleccon[0][1] <<", " << eleccon [0][2] <<")        A - Aircon ("<< eleccon[1][0] <<","<<" " << eleccon[1][1] << ", " << eleccon [1][2] <<")               T - TV ("<< eleccon[5][0] <<","<<" " << eleccon[5][1] << ", " << eleccon [5][2] <<")" << endl;
    cout << "     L - Laptop Charger ("<< eleccon[2][0] <<","<<" " << eleccon[2][1] <<", " << eleccon [2][2] << ")      C - Desktop Computer ("<< eleccon[3][0] <<","<<" " << eleccon[3][1] << ", " << eleccon [3][2] <<")     R - Wifi Router ("<< eleccon[7][0] <<","<<" " << eleccon[7][1] << ", " << eleccon [7][2] <<")" << endl;
    cout << "     P - Phone Charger ("<< eleccon[4][0] <<","<<" " << eleccon[4][1] <<", " << eleccon [4][2] << ")        I - Ilaw (Light Bulb) ("<< eleccon[6][0] <<","<<" " << eleccon[6][1] << ", " << eleccon [6][2] <<")     M - Microwave ("<< eleccon[8][0] <<","<<" " << eleccon[8][1] << ", " << eleccon [8][2] <<")" << endl;
    cout << endl;
    cout << "     W - Washing Machine ("<< eleccon[10][0] <<","<<" " << eleccon[10][1] <<", " << eleccon [10][2] << ")   D - Dryer ("<< eleccon[9][0] <<","<<" " << eleccon[9][1] <<", " << eleccon [9][2] << ")               F - Fridge ("<< eleccon[11][0] <<","<<" " << eleccon[11][1] <<", " << eleccon [11][2] << ")" << endl;
    cout << "     V - Rice Cooker ("<< eleccon[12][0] <<","<<" " << eleccon[12][1] <<", " << eleccon [12][2] << ")"     "        Y - Air Fryer ("<< eleccon[13][0] <<","<<" " << eleccon[13][1] <<", " << eleccon [13][2] << ")           Z - Laptop Cooler ("<< eleccon[14][0] <<","<<" " << eleccon[14][1] <<", " << eleccon [14][2] << ")" << endl;
    cout << "     U - Electric Kettle ("<< eleccon[15][0] <<","<<" " << eleccon[15][1] <<", " << eleccon [15][2] << ")"     "   Q - Radio ("<< eleccon[16][0] <<","<<" " << eleccon[16][1] <<", " << eleccon [16][2] << ")                  O - Toaster ("<< eleccon[17][0] <<","<<" " << eleccon[17][1] <<", " << eleccon [17][2] << ")" << endl;
    cout << "     S - Steam Iron ("<< eleccon[18][0] <<","<<" " << eleccon[18][1] <<", " << eleccon [18][2] << ")" << endl;
    cout << endl;
    cout << "**************************************************************************************************************" << endl;
            if (mode1 == true && ToggleAM == true){
                cout << "Mode: Advance Hour mode" << endl;
            } else if (mode2 == true && ToggleAM == true){
                cout << "Mode: Advance Power Rating Mode" << endl;
            } else if (mode3 == true && ToggleAM == true) {
                cout << "Mode: Advance Number Mode" << endl;
            } else if (mode1 == true) {
                cout << "Mode: Hour Mode" << endl;
            } else if (mode2 == true) {
                cout << "Mode: Power Rating Mode" << endl;
            } else if (mode3 == true) {
                cout << "Mode: Number Mode" << endl;
            }
            cout << "Enter your Choice" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cin >> menuselect;



                //switch system part 1
                switch (menuselect)
            {
                //Help Menu
                case '?':
                helpmenu ();
                repeat = true;
            break;

                //Resets All hour values placed by the user
                case 'X':
                for (int firstcount = 0; firstcount < 19; firstcount++)
            {
                eleccon[firstcount][0] = 0;
            }
                repeat = true;
                eleccon[11][0] = 24;
            break;

                case 'x':
                for (int firstcount = 0; firstcount < 19; firstcount++)
            {
                eleccon[firstcount][0] = 0;
            }
                repeat = true;
                eleccon[11][0] = 24;
            break;

                //Provides Results and Personalized Feedback
                case '=':
                result = (eleccon[0][2])*(eleccon[0][0]*eleccon[0][1]) + (eleccon[1][2])*(eleccon[1][0]*eleccon[1][1]) + (eleccon[2][2])*(eleccon[2][0]*eleccon[2][1]) + (eleccon[3][2])*(eleccon[3][0]*eleccon[3][1]) + (eleccon[4][2])*(eleccon[4][0]*eleccon[4][1]) + (eleccon[5][2])*(eleccon[5][0]*eleccon[5][1]) + (eleccon[6][2])*(eleccon[6][0]*eleccon[6][1]) + (eleccon[7][2])*(eleccon[7][0]*eleccon[7][1]) + (eleccon[8][2])*(eleccon[8][0]*eleccon[8][1]) + (eleccon[9][2])*(eleccon[9][0]*eleccon[9][1]) + (eleccon[10][2])*(eleccon[10][0]*eleccon[10][1]) + (eleccon[11][2])*(eleccon[11][0]*eleccon[11][1]) + (eleccon[12][2])*(eleccon[12][0]*eleccon[12][1]) + (eleccon[13][2])*(eleccon[13][0]*eleccon[13][1]) + (eleccon[14][2])*(eleccon[14][0]*eleccon[14][1])
                + (eleccon[15][2])*(eleccon[15][0]*eleccon[15][1]) + (eleccon[16][2])*(eleccon[16][0]*eleccon[16][1]) + (eleccon[17][2])*(eleccon[17][0]*eleccon[17][1]) + (eleccon[18][2])*(eleccon[18][0]*eleccon[18][1]);
                result2 = result / 1000;
                result3 = result2 * 9.59;
                cout << "Calculation Result: ";
                cout << result2 << " kWh or " << result3 << " Pesos " << endl;
                cout << "Keep this up and you can expect a cost of roughly " << result3 * 30 << " Pesos by the end of the month" << endl;
                cout << "" << endl;
                //Personalized Feedback system depending on result numbers


                //if power consumption is less than 10k watts feedback block
                if (result < 10000)
            {
                    cout << "Great results if its the consumption you had for a whole day!" << endl;
            }

                //If power consumption is less than 12k watts feedback block
                else if (result < 14000)
            {
                    cout << "Good results if its the consumption you had for a whole day." << endl;
            }

                //If power consumption is less than 15.5k watts feedback block
                else if (result <= 17500)
            {
                    cout << "Pretty bad results if its for a whole day." << endl;
            }
                //If power consumption is more than 15.5k watts feedback block
                else if (result > 17500)
            {
                    cout << "Terribe results, consider changing your way of using electricity." << endl;
            }

            //expanded area of the personalized feedback system
            cout << "" << endl;
            if (eleccon[1][0] > 12*eleccon[1][2] || eleccon[7][0] > 16*eleccon[7][2] || eleccon[4][0] > 11*eleccon[4][2] || eleccon[6][0] > 16*eleccon[6][2] && eleccon[6][1] < 25*eleccon[6][2] || eleccon[6][0] > 10*eleccon[6][2] && eleccon[6][1] >= 25*eleccon[6][2] || eleccon[6][0] > 7*eleccon[6][2] && eleccon[6][1] >= 55*eleccon[6][2]) {
                cout << "Additional Feedback:" << endl;
            }

            //aircon feedback
            if (eleccon[1][0] > 12*eleccon[1][2])
            {
                cout << "It looks like your using the aircon a bit too much, maybe try using an electric fan or waking up earlier?" << endl;
                cout << "" << endl;
            }

            //wifi feedback
            if (eleccon[7][0] > 16*eleccon[7][2])
            {
                cout << "Too much Wifi usage, consider turning it off when sleeping and sleeping for at least 8 hours long." << endl;
                cout << "" << endl;
            }

            //Phone charge feedback
            if (eleccon[4][0] > 11*eleccon[4][2])
            {
                cout << "Try to not overcharge your phone or use it this frequently. It's not good for your phone and overall energy consumption." << endl;
                cout << "" << endl;
            }

            //Light bulb feedbackS
            if (eleccon[6][0] > 16*eleccon[6][2] && eleccon[6][1] < 25*eleccon[6][2])
            {
                cout << "It looks like your using the lights too much, try closing them at night or when it is morning" << endl;
                cout << "" << endl;
            }

            else if (eleccon[6][0] > 10*eleccon[6][2] && eleccon[6][1] >= 25*eleccon[6][2])
            {
                cout << "You are likely using a fluoroscent bulb and your using too much power with it." << endl;
                cout << "Try using that bulb less or replace it with a LED or CFL bulb. Preferably LED" << endl;
                cout << "" << endl;
            }
            else if (eleccon[6][0] > 7*eleccon[6][2] && eleccon[6][1] >= 55*eleccon[6][2])
            {
                cout << "You are likely using a incandescent bulb and your using too much power with it." << endl;
                cout << "Try using that bulb less or replace it with a LED or CFL bulb. Preferably LED" << endl;
                cout << "" << endl;
            }


               repeattwo = true;
                while (repeattwo == true)
            {
                repeattwo = false;
                    cout << "Do you wish to continue using the program? (y/n) ";
                    cin >> contin;
                if (contin == 'y' || contin == 'Y')
            {
                    repeat = true;
            }
                else if (contin == 'n' || contin == 'N')
            {
                    cout << "Closing Program..." << endl;
                    repeat = false;
            }
                else
            {
                    cout << "Invalid Input, Please try again" << endl;
                    repeattwo = true;
            }



            }
                break;



                //switch system part 2
                //Give Hour value to fan
                    case 'E':
                    repeat = true;
                    cout << "How many hours did you use the fan? ";
                    cin >> eleccon[0][0];
                    TemporaryAntiInfinity ();
                break;

                //Give hour value to aircon
                    case 'A':
                    repeat = true;
                    cout << "How many hours did you use the Aircon? ";
                    cin >> eleccon[1][0];
                    TemporaryAntiInfinity ();
                break;

                //Give hour value to laptop charger
                    case 'L':
                    repeat = true;
                    cout << "How many hours did you use the Laptop Charger? ";
                    cin >> eleccon[2][0];
                    TemporaryAntiInfinity ();
                break;

                //Give hour value to desktop PC
                    case 'C':
                    repeat = true;
                    cout << "How many hours did you use the Desktop PC? ";
                    cin >> eleccon[3][0];
                    TemporaryAntiInfinity ();
                break;


                    case 'P':
                    repeat = true;
                    cout << "How many hours did you use the Phone Charger? ";
                    cin >> eleccon[4][0];
                    TemporaryAntiInfinity ();
                break;


                    case 'T':
                    repeat = true;
                    cout << "How many hours did you use the TV? ";
                    cin >> eleccon[5][0];
                    TemporaryAntiInfinity ();
                break;

                case '+':
                    if (ToggleAMC == 0){
                        ToggleAM = true;
                        ToggleAMC = 1;
                        repeat = true;
                    } else if (ToggleAMC == 1){
                        ToggleAM = false;
                        ToggleAMC = 0;
                        repeat = true;
                    }
                break;

                    case 'I':
                    repeat = true;
                    cout << "How many hours did you use the Light Bulb? ";
                    cin >> eleccon[6][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'R':
                    repeat = true;
                    cout << "How many hours did you use the Wifi Router? ";
                    cin >> eleccon[7][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'M':
                    repeat = true;
                    cout << "How many hours did you use the Microwave? ";
                    cin >> eleccon[8][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'W':
                    repeat = true;
                    cout << "How many hours did you use the Washing Machine? ";
                    cin >> eleccon[10][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'D':
                    repeat = true;
                    cout << "How many hours did you use the Dryer? ";
                    cin >> eleccon[9][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'H':
                        mode1 = true;
                        mode2 = false;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'J':
                        mode1 = false;
                        mode2 = true;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'K':
                        mode1 = false;
                        mode2 = false;
                        mode3 = true;
                        repeat = true;
                    break;

                //new new new new new
                case 'U':
                    repeat = true;
                    cout << "How many hours did you use the Electric Kettle?" << endl;
                    cin >> eleccon[15][0];
                    TemporaryAntiInfinity ();
                break;

                case 'Q':
                    repeat = true;
                    cout << "How many hours did you use the Radio?" << endl;
                    cin >> eleccon[16][0];
                    TemporaryAntiInfinity ();
                break;

                case 'O':
                    repeat = true;
                    cout << "How many hours did you use the Toaster?" << endl;
                    cin >> eleccon[17][0];
                    TemporaryAntiInfinity ();
                break;

                case 'S':
                    repeat = true;
                    cout << "How many hours did you use the Steam Iron?" << endl;
                    cin >> eleccon[18][0];
                    TemporaryAntiInfinity ();
                break;

                 //new new new new new
                case 'u':
                    repeat = true;
                    cout << "How many hours did you use the Electric Kettle?" << endl;
                    cin >> eleccon[15][0];
                    TemporaryAntiInfinity ();
                break;

                case 'q':
                    repeat = true;
                    cout << "How many hours did you use the Radio?" << endl;
                    cin >> eleccon[16][0];
                    TemporaryAntiInfinity ();
                break;

                case 'o':
                    repeat = true;
                    cout << "How many hours did you use the Toaster?" << endl;
                    cin >> eleccon[17][0];
                    TemporaryAntiInfinity ();
                break;

                case 's':
                    repeat = true;
                    cout << "How many hours did you use the Steam Iron?" << endl;
                    cin >> eleccon[18][0];
                    TemporaryAntiInfinity ();
                break;


                //new new new
                case 'F':
                    repeat = true;
                    cout << "How many hours did you use the Fridge?" << endl;
                    cin >> eleccon[11][0];
                    TemporaryAntiInfinity ();
                break;

                case 'V':
                    repeat = true;
                    cout << "How many hours did you use the Rice Cooker?" << endl;
                    cin >> eleccon[12][0];
                    TemporaryAntiInfinity ();
                break;

                case 'Y':
                    repeat = true;
                    cout << "How many hours did you use the Air Fryer?" << endl;
                    cin >> eleccon[13][0];
                    TemporaryAntiInfinity ();
                break;

                case 'Z':
                    repeat = true;
                    cout << "How many hours did you use the Laptop Cooler?" << endl;
                    cin >> eleccon[14][0];
                    TemporaryAntiInfinity ();
                break;
// break



                //new new new
                case 'f':
                    repeat = true;
                    cout << "How many hours did you use the Fridge?" << endl;
                    cin >> eleccon[11][0];
                    TemporaryAntiInfinity ();
                break;

                case 'v':
                    repeat = true;
                    cout << "How many hours did you use the Rice Cooker?" << endl;
                    cin >> eleccon[12][0];
                    TemporaryAntiInfinity ();
                break;

                case 'y':
                    repeat = true;
                    cout << "How many hours did you use the Air Fryer?" << endl;
                    cin >> eleccon[13][0];
                    TemporaryAntiInfinity ();
                break;

                case 'z':
                    repeat = true;
                    cout << "How many hours did you use the Laptop Cooler?" << endl;
                    cin >> eleccon[14][0];
                    TemporaryAntiInfinity ();
                break;


                    case 'e':
                    repeat = true;
                    cout << "How many hours did you use the fan? ";
                    cin >> eleccon[0][0];
                    TemporaryAntiInfinity ();
                break;

                //Give hour value to aircon
                    case 'a':
                    repeat = true;
                    cout << "How many hours did you use the Aircon? ";
                    cin >> eleccon[1][0];
                    TemporaryAntiInfinity ();
                break;

                //Give hour value to laptop charger
                    case 'l':
                    repeat = true;
                    cout << "How many hours did you use the Laptop Charger? ";
                    cin >> eleccon[2][0];
                    TemporaryAntiInfinity ();
                break;

                //Give hour value to desktop PC
                    case 'c':
                    repeat = true;
                    cout << "How many hours did you use the Desktop PC? ";
                    cin >> eleccon[3][0];
                    TemporaryAntiInfinity ();
                break;


                    case 'p':
                    repeat = true;
                    cout << "How many hours did you use the Phone Charger? ";
                    cin >> eleccon[4][0];
                    TemporaryAntiInfinity ();
                break;


                    case 't':
                    repeat = true;
                    cout << "How many hours did you use the TV? ";
                    cin >> eleccon[5][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'i':
                    repeat = true;
                    cout << "How many hours did you use the Light Bulb? ";
                    cin >> eleccon[6][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'r':
                    repeat = true;
                    cout << "How many hours did you use the Wifi Router? ";
                    cin >> eleccon[7][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'm':
                    repeat = true;
                    cout << "How many hours did you use the Microwave? ";
                    cin >> eleccon[8][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'w':
                    repeat = true;
                    cout << "How many hours did you use the Washing Machine? ";
                    cin >> eleccon[10][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'd':
                    repeat = true;
                    cout << "How many hours did you use the Dryer? ";
                    cin >> eleccon[9][0];
                    TemporaryAntiInfinity ();
                break;

                    case 'h':
                        mode1 = true;
                        mode2 = false;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'j':
                        mode1 = false;
                        mode2 = true;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'k':
                        mode1 = false;
                        mode2 = false;
                        mode3 = true;
                        repeat = true;
                    break;



                    default:
                    repeat = true;
                    cout << "INVALID INPUT, PLEASE TRY AGAIN" << endl;
                };
        }



        //Advance Power Rating Mode


        else if (ToggleAM == true && mode2 == true){
            MenuResetPosition ();

    cout << "**************************************************************************************************************" <<endl;
    cout << "*                                                                                                            *" <<endl;
    cout << "*                                     Energy Consumption Feedback Program                                    *" <<endl;
    cout << "*                                                                                                            *" <<endl;
    cout << "**************************************************************************************************************" <<endl;
    cout << endl;
    cout << "     Special Commands:" << endl;
    cout << "     = - Calculate                      X - Clear all input                  + - Advance Mode" << endl;
    cout << "     H - Toggle Hours Mode              J - Toggle Power Rating Mode         K - Toggle Number Mode" << endl;
    cout << "     ? - Help Menu" << endl;
    cout << endl;
    cout << "     Appliances:" << endl;
    cout << "     E - Electric Fan ("<< eleccon[0][0] <<","<<" " << eleccon[0][1] <<", " << eleccon [0][2] <<")        A - Aircon ("<< eleccon[1][0] <<","<<" " << eleccon[1][1] << ", " << eleccon [1][2] <<")               T - TV ("<< eleccon[5][0] <<","<<" " << eleccon[5][1] << ", " << eleccon [5][2] <<")" << endl;
    cout << "     L - Laptop Charger ("<< eleccon[2][0] <<","<<" " << eleccon[2][1] <<", " << eleccon [2][2] << ")      C - Desktop Computer ("<< eleccon[3][0] <<","<<" " << eleccon[3][1] << ", " << eleccon [3][2] <<")     R - Wifi Router ("<< eleccon[7][0] <<","<<" " << eleccon[7][1] << ", " << eleccon [7][2] <<")" << endl;
    cout << "     P - Phone Charger ("<< eleccon[4][0] <<","<<" " << eleccon[4][1] <<", " << eleccon [4][2] << ")        I - Ilaw (Light Bulb) ("<< eleccon[6][0] <<","<<" " << eleccon[6][1] << ", " << eleccon [6][2] <<")     M - Microwave ("<< eleccon[8][0] <<","<<" " << eleccon[8][1] << ", " << eleccon [8][2] <<")" << endl;
    cout << endl;
    cout << "     W - Washing Machine ("<< eleccon[10][0] <<","<<" " << eleccon[10][1] <<", " << eleccon [10][2] << ")   D - Dryer ("<< eleccon[9][0] <<","<<" " << eleccon[9][1] <<", " << eleccon [9][2] << ")               F - Fridge ("<< eleccon[11][0] <<","<<" " << eleccon[11][1] <<", " << eleccon [11][2] << ")" << endl;
    cout << "     V - Rice Cooker ("<< eleccon[12][0] <<","<<" " << eleccon[12][1] <<", " << eleccon [12][2] << ")"     "        Y - Air Fryer ("<< eleccon[13][0] <<","<<" " << eleccon[13][1] <<", " << eleccon [13][2] << ")           Z - Laptop Cooler ("<< eleccon[14][0] <<","<<" " << eleccon[14][1] <<", " << eleccon [14][2] << ")" << endl;
    cout << "     U - Electric Kettle ("<< eleccon[15][0] <<","<<" " << eleccon[15][1] <<", " << eleccon [15][2] << ")"     "   Q - Radio ("<< eleccon[16][0] <<","<<" " << eleccon[16][1] <<", " << eleccon [16][2] << ")                  O - Toaster ("<< eleccon[17][0] <<","<<" " << eleccon[17][1] <<", " << eleccon [17][2] << ")" << endl;
    cout << "     S - Steam Iron ("<< eleccon[18][0] <<","<<" " << eleccon[18][1] <<", " << eleccon [18][2] << ")" << endl;
    cout << endl;
    cout << "**************************************************************************************************************" << endl;
            if (mode1 == true && ToggleAM == true){
                cout << "Mode: Advance Hour mode" << endl;
            } else if (mode2 == true && ToggleAM == true){
                cout << "Mode: Advance Power Rating Mode" << endl;
            } else if (mode3 == true && ToggleAM == true) {
                cout << "Mode: Advance Number Mode" << endl;
            } else if (mode1 == true) {
                cout << "Mode: Hour Mode" << endl;
            } else if (mode2 == true) {
                cout << "Mode: Power Rating Mode" << endl;
            } else if (mode3 == true) {
                cout << "Mode: Number Mode" << endl;
            }
            cout << "Enter your Choice" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cin >> menuselect;



                //switch system part 1
                switch (menuselect)
            {
                //Help Menu
                case '?':
                helpmenu ();
                repeat = true;
            break;

                //Resets All hour values placed by the user
                case 'X':
                eleccon[0][1] = 80;
                eleccon[1][1] = 650;
                eleccon[2][1] = 75;
                eleccon[3][1] = 200;
                eleccon[4][1] = 5;
                eleccon[5][1] = 100;
                eleccon[6][1] = 30;
                eleccon[7][1] = 20;
                eleccon[8][1] = 1200;
                eleccon[9][1] = 3400;
                eleccon[10][1] = 2250;
                eleccon[11][1] = 565;
                eleccon[12][1] = 200;
                eleccon[13][1] = 1300;
                eleccon[14][1] = 3;
                eleccon[15][1] = 1500;
                eleccon[16][1] = 5;
                eleccon[17][1] = 1100;
                eleccon[18][1] = 1000;
                repeat = true;
            break;

                case 'x':
                eleccon[0][1] = 80;
                eleccon[1][1] = 650;
                eleccon[2][1] = 75;
                eleccon[3][1] = 200;
                eleccon[4][1] = 5;
                eleccon[5][1] = 100;
                eleccon[6][1] = 30;
                eleccon[7][1] = 20;
                eleccon[8][1] = 1200;
                eleccon[9][1] = 3400;
                eleccon[10][1] = 2250;
                eleccon[11][1] = 565;
                eleccon[12][1] = 200;
                eleccon[13][1] = 1300;
                eleccon[14][1] = 3;
                eleccon[15][1] = 1500;
                eleccon[16][1] = 5;
                eleccon[17][1] = 1100;
                eleccon[18][1] = 1000;
                repeat = true;
            break;

                //Provides Results and Personalized Feedback
                case '=':
                result = (eleccon[0][2])*(eleccon[0][0]*eleccon[0][1]) + (eleccon[1][2])*(eleccon[1][0]*eleccon[1][1]) + (eleccon[2][2])*(eleccon[2][0]*eleccon[2][1]) + (eleccon[3][2])*(eleccon[3][0]*eleccon[3][1]) + (eleccon[4][2])*(eleccon[4][0]*eleccon[4][1]) + (eleccon[5][2])*(eleccon[5][0]*eleccon[5][1]) + (eleccon[6][2])*(eleccon[6][0]*eleccon[6][1]) + (eleccon[7][2])*(eleccon[7][0]*eleccon[7][1]) + (eleccon[8][2])*(eleccon[8][0]*eleccon[8][1]) + (eleccon[9][2])*(eleccon[9][0]*eleccon[9][1]) + (eleccon[10][2])*(eleccon[10][0]*eleccon[10][1]) + (eleccon[11][2])*(eleccon[11][0]*eleccon[11][1]) + (eleccon[12][2])*(eleccon[12][0]*eleccon[12][1]) + (eleccon[13][2])*(eleccon[13][0]*eleccon[13][1]) + (eleccon[14][2])*(eleccon[14][0]*eleccon[14][1])
                + (eleccon[15][2])*(eleccon[15][0]*eleccon[15][1]) + (eleccon[16][2])*(eleccon[16][0]*eleccon[16][1]) + (eleccon[17][2])*(eleccon[17][0]*eleccon[17][1]) + (eleccon[18][2])*(eleccon[18][0]*eleccon[18][1]);
                result2 = result / 1000;
                result3 = result2 * 9.59;
                cout << "Calculation Result: ";
                cout << result2 << " kWh or " << result3 << " Pesos " << endl;
                cout << "Keep this up and you can expect a cost of roughly " << result3 * 30 << " Pesos by the end of the month" << endl;
                cout << "" << endl;
                //Personalized Feedback system depending on result numbers


                //if power consumption is less than 10k watts feedback block
                if (result < 10000)
            {
                    cout << "Great results if its the consumption you had for a whole day!" << endl;
            }

                //If power consumption is less than 12k watts feedback block
                else if (result < 14000)
            {
                    cout << "Good results if its the consumption you had for a whole day." << endl;
            }

                //If power consumption is less than 15.5k watts feedback block
                else if (result <= 17500)
            {
                    cout << "Pretty bad results if its for a whole day." << endl;
            }
                //If power consumption is more than 15.5k watts feedback block
                else if (result > 17500)
            {
                    cout << "Terribe results, consider changing your way of using electricity." << endl;
            }

            //expanded area of the personalized feedback system
            cout << "" << endl;
            if (eleccon[1][0] > 12*eleccon[1][2] || eleccon[7][0] > 16*eleccon[7][2] || eleccon[4][0] > 11*eleccon[4][2] || eleccon[6][0] > 16*eleccon[6][2] && eleccon[6][1] < 25*eleccon[6][2] || eleccon[6][0] > 10*eleccon[6][2] && eleccon[6][1] >= 25*eleccon[6][2] || eleccon[6][0] > 7*eleccon[6][2] && eleccon[6][1] >= 55*eleccon[6][2]) {
                cout << "Additional Feedback:" << endl;
            }

            //aircon feedback
            if (eleccon[1][0] > 12*eleccon[1][2])
            {
                cout << "It looks like your using the aircon a bit too much, maybe try using an electric fan or waking up earlier?" << endl;
                cout << "" << endl;
            }

            //wifi feedback
            if (eleccon[7][0] > 16*eleccon[7][2])
            {
                cout << "Too much Wifi usage, consider turning it off when sleeping and sleeping for at least 8 hours long." << endl;
                cout << "" << endl;
            }

            //Phone charge feedback
            if (eleccon[4][0] > 11*eleccon[4][2])
            {
                cout << "Try to not overcharge your phone or use it this frequently. It's not good for your phone and overall energy consumption." << endl;
                cout << "" << endl;
            }

            //Light bulb feedbackS
            if (eleccon[6][0] > 16*eleccon[6][2] && eleccon[6][1] < 25*eleccon[6][2])
            {
                cout << "It looks like your using the lights too much, try closing them at night or when it is morning" << endl;
                cout << "" << endl;
            }

            else if (eleccon[6][0] > 10*eleccon[6][2] && eleccon[6][1] >= 25*eleccon[6][2])
            {
                cout << "You are likely using a fluoroscent bulb and your using too much power with it." << endl;
                cout << "Try using that bulb less or replace it with a LED or CFL bulb. Preferably LED" << endl;
                cout << "" << endl;
            }
            else if (eleccon[6][0] > 7*eleccon[6][2] && eleccon[6][1] >= 55*eleccon[6][2])
            {
                cout << "You are likely using a incandescent bulb and your using too much power with it." << endl;
                cout << "Try using that bulb less or replace it with a LED or CFL bulb. Preferably LED" << endl;
                cout << "" << endl;
            }


               repeattwo = true;
                while (repeattwo == true)
            {
                repeattwo = false;
                    cout << "Do you wish to continue using the program? (y/n) ";
                    cin >> contin;
                if (contin == 'y' || contin == 'Y')
            {
                    repeat = true;
            }
                else if (contin == 'n' || contin == 'N')
            {
                    cout << "Closing Program..." << endl;
                    repeat = false;
            }
                else
            {
                    cout << "Invalid Input, Please try again" << endl;
                    repeattwo = true;
            }



            }
                break;

                //switch system part 2
                //Give power rating value for fan


                //new new new new new
                case 'U':
                    repeat = true;
                    cout << "What is your Electric Kettle power rating?" << endl;
                    cin >> eleccon[15][1];
                    TemporaryAntiInfinity ();
                break;

                case 'Q':
                    repeat = true;
                    cout << "What is your Radio power rating?" << endl;
                    cin >> eleccon[16][1];
                    TemporaryAntiInfinity ();
                break;

                case 'O':
                    repeat = true;
                    cout << "What is your Toaster power rating?" << endl;
                    cin >> eleccon[17][1];
                    TemporaryAntiInfinity ();
                break;

                case 'S':
                    repeat = true;
                    cout << "What is your Steam Iron power rating?" << endl;
                    cin >> eleccon[18][1];
                    TemporaryAntiInfinity ();
                break;

                case 'u':
                    repeat = true;
                    cout << "What is your Electric Kettle power rating?" << endl;
                    cin >> eleccon[15][1];
                    TemporaryAntiInfinity ();
                break;

                case 'q':
                    repeat = true;
                    cout << "What is your Radio power rating?" << endl;
                    cin >> eleccon[16][1];
                    TemporaryAntiInfinity ();
                break;

                case 'o':
                    repeat = true;
                    cout << "What is your Toaster power rating?" << endl;
                    cin >> eleccon[17][1];
                    TemporaryAntiInfinity ();
                break;

                case 's':
                    repeat = true;
                    cout << "What is your Steam Iron power rating?" << endl;
                    cin >> eleccon[18][1];
                    TemporaryAntiInfinity ();
                break;

                    case 'E':
                    repeat = true;
                    cout << "What is your fan power rating? ";
                    cin >> eleccon[0][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating value for aircon
                    case 'A':
                    repeat = true;
                    cout << "What is your aircon power rating? ";
                    cin >> eleccon[1][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating value for laptop charger
                    case 'L':
                    repeat = true;
                    cout << "What is your laptop charger power rating? ";
                    cin >> eleccon[2][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating value for desktop PC
                    case 'C':
                    repeat = true;
                    cout << "What is your desktop computer power rating? ";
                    cin >> eleccon[3][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating value for phone charger
                    case 'P':
                    repeat = true;
                    cout << "What is your phone charger power rating? ";
                    cin >> eleccon[4][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating for TV
                    case 'T':
                    repeat = true;
                    cout << "What is your TV power rating? ";
                    cin >> eleccon[5][1];
                    TemporaryAntiInfinity ();
                break;

                case '+':
                    if (ToggleAMC == 0){
                        ToggleAM = true;
                        ToggleAMC = 1;
                        repeat = true;
                    } else if (ToggleAMC == 1){
                        ToggleAM = false;
                        ToggleAMC = 0;
                        repeat = true;
                    }
                break;

                //Give power rating for light bulb
                    case 'I':
                    repeat = true;
                    cout << "What is your light bulb power rating? ";
                    cin >> eleccon[6][1];
                    TemporaryAntiInfinity ();
                break;
                //Give power rating for wifi router
                    case 'R':
                    repeat = true;
                    cout << "What is your wifi router power rating? ";
                    cin >> eleccon[7][1];
                    TemporaryAntiInfinity ();
                break;
                //Give power rating for microwave
                    case 'M':
                    repeat = true;
                    cout << "What is your microwave power rating? ";
                    cin >> eleccon[8][1];
                    TemporaryAntiInfinity ();
                break;
                //Give power rating for washing machine
                    case 'W':
                    repeat = true;
                    cout << "What is your washing machine power rating? ";
                    cin >> eleccon[10][1];
                    TemporaryAntiInfinity ();
                break;
                //Give power rating for Dryer
                    case 'D':
                    repeat = true;
                    cout << "What is your dryer power rating? ";
                    cin >> eleccon[9][1];
                    TemporaryAntiInfinity ();
                break;
                    case 'H':
                        mode1 = true;
                        mode2 = false;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'J':
                        mode1 = false;
                        mode2 = true;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'K':
                        mode1 = false;
                        mode2 = false;
                        mode3 = true;
                        repeat = true;
                    break;

                //new new new
                case 'F':
                    repeat = true;
                    cout << "What is your Fridge power rating?" << endl;
                    cin >> eleccon[11][1];
                    TemporaryAntiInfinity ();
                break;

                case 'V':
                    repeat = true;
                    cout << "What is your Rice Cooker power rating?" << endl;
                    cin >> eleccon[12][1];
                    TemporaryAntiInfinity ();
                break;

                case 'Y':
                    repeat = true;
                    cout << "What is your Air Fryer power rating?" << endl;
                    cin >> eleccon[13][1];
                    TemporaryAntiInfinity ();
                break;

                case 'Z':
                    repeat = true;
                    cout << "What is your Laptop Cooler power rating?" << endl;
                    cin >> eleccon[14][1];
                    TemporaryAntiInfinity ();
                break;



//break  s
                    case 'e':
                    repeat = true;
                    cout << "What is your fan power rating? ";
                    cin >> eleccon[0][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating value for aircon
                    case 'a':
                    repeat = true;
                    cout << "What is your aircon power rating? ";
                    cin >> eleccon[1][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating value for laptop charger
                    case 'l':
                    repeat = true;
                    cout << "What is your laptop charger power rating? ";
                    cin >> eleccon[2][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating value for desktop PC
                    case 'c':
                    repeat = true;
                    cout << "What is your desktop computer power rating? ";
                    cin >> eleccon[3][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating value for phone charger
                    case 'p':
                    repeat = true;
                    cout << "What is your phone charger power rating? ";
                    cin >> eleccon[4][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating for TV
                    case 't':
                    repeat = true;
                    cout << "What is your TV power rating? ";
                    cin >> eleccon[5][1];
                    TemporaryAntiInfinity ();
                break;

                //Give power rating for light bulb
                    case 'i':
                    repeat = true;
                    cout << "What is your light bulb power rating? ";
                    cin >> eleccon[6][1];
                    TemporaryAntiInfinity ();
                break;
                //Give power rating for wifi router
                    case 'r':
                    repeat = true;
                    cout << "What is your wifi router power rating? ";
                    cin >> eleccon[7][1];
                    TemporaryAntiInfinity ();
                break;
                //Give power rating for microwave
                    case 'm':
                    repeat = true;
                    cout << "What is your microwave power rating? ";
                    cin >> eleccon[8][1];
                    TemporaryAntiInfinity ();
                break;
                //Give power rating for washing machine
                    case 'w':
                    repeat = true;
                    cout << "What is your washing machine power rating? ";
                    cin >> eleccon[10][1];
                    TemporaryAntiInfinity ();
                break;
                //Give power rating for Dryer
                    case 'd':
                    repeat = true;
                    cout << "What is your dryer power rating? ";
                    cin >> eleccon[9][1];
                    TemporaryAntiInfinity ();
                break;
                    case 'h':
                        mode1 = true;
                        mode2 = false;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'j':
                        mode1 = false;
                        mode2 = true;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'k':
                        mode1 = false;
                        mode2 = false;
                        mode3 = true;
                        repeat = true;
                    break;


                //new new new
                case 'f':
                    repeat = true;
                    cout << "What is your Fridge power rating?" << endl;
                    cin >> eleccon[11][1];
                    TemporaryAntiInfinity ();
                break;

                case 'v':
                    repeat = true;
                    cout << "What is your Rice Cooker power rating?" << endl;
                    cin >> eleccon[12][1];
                    TemporaryAntiInfinity ();
                break;

                case 'y':
                    repeat = true;
                    cout << "What is your Air Fryer power rating?" << endl;
                    cin >> eleccon[13][1];
                    TemporaryAntiInfinity ();
                break;

                case 'z':
                    repeat = true;
                    cout << "What is your Laptop Cooler power rating?" << endl;
                    cin >> eleccon[14][1];
                    TemporaryAntiInfinity ();
                break;

                    default:
                    repeat = true;
                    cout << "INVALID INPUT, PLEASE TRY AGAIN" << endl;
                };

                }




      //Advance number mode

        else if (ToggleAM == true && mode3 == true){
            MenuResetPosition ();

    cout << "**************************************************************************************************************" <<endl;
    cout << "*                                                                                                            *" <<endl;
    cout << "*                                     Energy Consumption Feedback Program                                    *" <<endl;
    cout << "*                                                                                                            *" <<endl;
    cout << "**************************************************************************************************************" <<endl;
    cout << endl;
    cout << "     Special Commands:" << endl;
    cout << "     = - Calculate                      X - Clear all input                  + - Advance Mode" << endl;
    cout << "     H - Toggle Hours Mode              J - Toggle Power Rating Mode         K - Toggle Number Mode" << endl;
    cout << "     ? - Help Menu" << endl;
    cout << endl;
    cout << "     Appliances:" << endl;
    cout << "     E - Electric Fan ("<< eleccon[0][0] <<","<<" " << eleccon[0][1] <<", " << eleccon [0][2] <<")        A - Aircon ("<< eleccon[1][0] <<","<<" " << eleccon[1][1] << ", " << eleccon [1][2] <<")               T - TV ("<< eleccon[5][0] <<","<<" " << eleccon[5][1] << ", " << eleccon [5][2] <<")" << endl;
    cout << "     L - Laptop Charger ("<< eleccon[2][0] <<","<<" " << eleccon[2][1] <<", " << eleccon [2][2] << ")      C - Desktop Computer ("<< eleccon[3][0] <<","<<" " << eleccon[3][1] << ", " << eleccon [3][2] <<")     R - Wifi Router ("<< eleccon[7][0] <<","<<" " << eleccon[7][1] << ", " << eleccon [7][2] <<")" << endl;
    cout << "     P - Phone Charger ("<< eleccon[4][0] <<","<<" " << eleccon[4][1] <<", " << eleccon [4][2] << ")        I - Ilaw (Light Bulb) ("<< eleccon[6][0] <<","<<" " << eleccon[6][1] << ", " << eleccon [6][2] <<")     M - Microwave ("<< eleccon[8][0] <<","<<" " << eleccon[8][1] << ", " << eleccon [8][2] <<")" << endl;
    cout << endl;
    cout << "     W - Washing Machine ("<< eleccon[10][0] <<","<<" " << eleccon[10][1] <<", " << eleccon [10][2] << ")   D - Dryer ("<< eleccon[9][0] <<","<<" " << eleccon[9][1] <<", " << eleccon [9][2] << ")               F - Fridge ("<< eleccon[11][0] <<","<<" " << eleccon[11][1] <<", " << eleccon [11][2] << ")" << endl;
    cout << "     V - Rice Cooker ("<< eleccon[12][0] <<","<<" " << eleccon[12][1] <<", " << eleccon [12][2] << ")"     "        Y - Air Fryer ("<< eleccon[13][0] <<","<<" " << eleccon[13][1] <<", " << eleccon [13][2] << ")           Z - Laptop Cooler ("<< eleccon[14][0] <<","<<" " << eleccon[14][1] <<", " << eleccon [14][2] << ")" << endl;
    cout << "     U - Electric Kettle ("<< eleccon[15][0] <<","<<" " << eleccon[15][1] <<", " << eleccon [15][2] << ")"     "   Q - Radio ("<< eleccon[16][0] <<","<<" " << eleccon[16][1] <<", " << eleccon [16][2] << ")                  O - Toaster ("<< eleccon[17][0] <<","<<" " << eleccon[17][1] <<", " << eleccon [17][2] << ")" << endl;
    cout << "     S - Steam Iron ("<< eleccon[18][0] <<","<<" " << eleccon[18][1] <<", " << eleccon [18][2] << ")" << endl;
    cout << endl;
    cout << "**************************************************************************************************************" << endl;
            if (mode1 == true && ToggleAM == true){
                cout << "Mode: Advance Hour mode" << endl;
            } else if (mode2 == true && ToggleAM == true){
                cout << "Mode: Advance Power Rating Mode" << endl;
            } else if (mode3 == true && ToggleAM == true) {
                cout << "Mode: Advance Number Mode" << endl;
            } else if (mode1 == true) {
                cout << "Mode: Hour Mode" << endl;
            } else if (mode2 == true) {
                cout << "Mode: Power Rating Mode" << endl;
            } else if (mode3 == true) {
                cout << "Mode: Number Mode" << endl;
            }
            cout << "Enter your Choice" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cin >> menuselect;



                //switch system part 1
                switch (menuselect)
            {
                //Help Menu
                case '?':
                helpmenu ();
                repeat = true;
            break;

                //Resets All hour values placed by the user
                case 'X':
                for (int firstcount = 0; firstcount < 19; firstcount++)
            {
                eleccon[firstcount][2] = 1;
            }
                repeat = true;
            break;

                case 'x':
                for (int firstcount = 0; firstcount < 19; firstcount++)
            {
                eleccon[firstcount][2] = 1;
            }
                repeat = true;
            break;

                //Provides Results and Personalized Feedback
                case '=':
                result = (eleccon[0][2])*(eleccon[0][0]*eleccon[0][1]) + (eleccon[1][2])*(eleccon[1][0]*eleccon[1][1]) + (eleccon[2][2])*(eleccon[2][0]*eleccon[2][1]) + (eleccon[3][2])*(eleccon[3][0]*eleccon[3][1]) + (eleccon[4][2])*(eleccon[4][0]*eleccon[4][1]) + (eleccon[5][2])*(eleccon[5][0]*eleccon[5][1]) + (eleccon[6][2])*(eleccon[6][0]*eleccon[6][1]) + (eleccon[7][2])*(eleccon[7][0]*eleccon[7][1]) + (eleccon[8][2])*(eleccon[8][0]*eleccon[8][1]) + (eleccon[9][2])*(eleccon[9][0]*eleccon[9][1]) + (eleccon[10][2])*(eleccon[10][0]*eleccon[10][1]) + (eleccon[11][2])*(eleccon[11][0]*eleccon[11][1]) + (eleccon[12][2])*(eleccon[12][0]*eleccon[12][1]) + (eleccon[13][2])*(eleccon[13][0]*eleccon[13][1]) + (eleccon[14][2])*(eleccon[14][0]*eleccon[14][1])
                + (eleccon[15][2])*(eleccon[15][0]*eleccon[15][1]) + (eleccon[16][2])*(eleccon[16][0]*eleccon[16][1]) + (eleccon[17][2])*(eleccon[17][0]*eleccon[17][1]) + (eleccon[18][2])*(eleccon[18][0]*eleccon[18][1]);
                result3 = result2 * 9.59;
                cout << "Calculation Result: ";
                cout << result2 << " kWh or " << result3 << " Pesos " << endl;
                cout << "Keep this up and you can expect a cost of roughly " << result3 * 30 << " Pesos by the end of the month" << endl;
                cout << "" << endl;
                //Personalized Feedback system depending on result numbers


                //if power consumption is less than 10k watts feedback block
                if (result < 10000)
            {
                    cout << "Great results if its the consumption you had for a whole day!" << endl;
            }

                //If power consumption is less than 12k watts feedback block
                else if (result < 14000)
            {
                    cout << "Good results if its the consumption you had for a whole day." << endl;
            }

                //If power consumption is less than 15.5k watts feedback block
                else if (result <= 17500)
            {
                    cout << "Pretty bad results if its for a whole day." << endl;
            }
                //If power consumption is more than 15.5k watts feedback block
                else if (result > 17500)
            {
                    cout << "Terribe results, consider changing your way of using electricity." << endl;
            }

            //expanded area of the personalized feedback system
            cout << "" << endl;
            if (eleccon[1][0] > 12*eleccon[1][2] || eleccon[7][0] > 16*eleccon[7][2] || eleccon[4][0] > 11*eleccon[4][2] || eleccon[6][0] > 16*eleccon[6][2] && eleccon[6][1] < 25*eleccon[6][2] || eleccon[6][0] > 10*eleccon[6][2] && eleccon[6][1] >= 25*eleccon[6][2] || eleccon[6][0] > 7*eleccon[6][2] && eleccon[6][1] >= 55*eleccon[6][2]) {
                cout << "Additional Feedback:" << endl;
            }

            //aircon feedback
            if (eleccon[1][0] > 12*eleccon[1][2])
            {
                cout << "It looks like your using the aircon a bit too much, maybe try using an electric fan or waking up earlier?" << endl;
                cout << "" << endl;
            }

            //wifi feedback
            if (eleccon[7][0] > 16*eleccon[7][2])
            {
                cout << "Too much Wifi usage, consider turning it off when sleeping and sleeping for at least 8 hours long." << endl;
                cout << "" << endl;
            }

            //Phone charge feedback
            if (eleccon[4][0] > 11*eleccon[4][2])
            {
                cout << "Try to not overcharge your phone or use it this frequently. It's not good for your phone and overall energy consumption." << endl;
                cout << "" << endl;
            }

            //Light bulb feedbackS
            if (eleccon[6][0] > 16*eleccon[6][2] && eleccon[6][1] < 25*eleccon[6][2])
            {
                cout << "It looks like your using the lights too much, try closing them at night or when it is morning" << endl;
                cout << "" << endl;
            }

            else if (eleccon[6][0] > 10*eleccon[6][2] && eleccon[6][1] >= 25*eleccon[6][2])
            {
                cout << "You are likely using a fluoroscent bulb and your using too much power with it." << endl;
                cout << "Try using that bulb less or replace it with a LED or CFL bulb. Preferably LED" << endl;
                cout << "" << endl;
            }
            else if (eleccon[6][0] > 7*eleccon[6][2] && eleccon[6][1] >= 55*eleccon[6][2])
            {
                cout << "You are likely using a incandescent bulb and your using too much power with it." << endl;
                cout << "Try using that bulb less or replace it with a LED or CFL bulb. Preferably LED" << endl;
                cout << "" << endl;
            }


               repeattwo = true;
                while (repeattwo == true)
            {
                repeattwo = false;
                    cout << "Do you wish to continue using the program? (y/n) ";
                    cin >> contin;
                if (contin == 'y' || contin == 'Y')
            {
                    repeat = true;
            }
                else if (contin == 'n' || contin == 'N')
            {
                    cout << "Closing Program..." << endl;
                    repeat = false;
            }
                else
            {
                    cout << "Invalid Input, Please try again" << endl;
                    repeattwo = true;
            }



            }
                break;

                //switch system part 2
                //Give number of fans

                case 'U':
                    repeat = true;
                    cout << "How many Electric Kettles do you have?" << endl;
                    cin >> eleccon[15][2];
                    TemporaryAntiInfinity ();
                break;

                case 'Q':
                    repeat = true;
                    cout << "How many Radios do you have?" << endl;
                    cin >> eleccon[16][2];
                    TemporaryAntiInfinity ();
                break;

                case 'O':
                    repeat = true;
                    cout << "How many Toasters do you have?" << endl;
                    cin >> eleccon[17][2];
                    TemporaryAntiInfinity ();
                break;

                case 'S':
                    repeat = true;
                    cout << "How many Steam Irons do you have?" << endl;
                    cin >> eleccon[18][2];
                    TemporaryAntiInfinity ();
                break;

                case 'u':
                    repeat = true;
                    cout << "How many Electric Kettles do you have?" << endl;
                    cin >> eleccon[15][2];
                    TemporaryAntiInfinity ();
                break;

                case 'q':
                    repeat = true;
                    cout << "How many Radios do you have?" << endl;
                    cin >> eleccon[16][2];
                    TemporaryAntiInfinity ();
                break;

                case 'o':
                    repeat = true;
                    cout << "How many Toasters do you have?" << endl;
                    cin >> eleccon[17][2];
                    TemporaryAntiInfinity ();
                break;

                case 's':
                    repeat = true;
                    cout << "How many Steam Irons do you have?" << endl;
                    cin >> eleccon[18][2];
                    TemporaryAntiInfinity ();
                break;

                    case 'E':
                    repeat = true;
                    cout << "How many fans do you have? ";
                    cin >> eleccon[0][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of aircons
                    case 'A':
                    repeat = true;
                    cout << "How many aircons do you have? ";
                    cin >> eleccon[1][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of laptop chargers
                    case 'L':
                    repeat = true;
                    cout << "How many laptop chargers do you have? ";
                    cin >> eleccon[2][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of desktop PC
                    case 'C':
                    repeat = true;
                    cout << "How many desktop PCs do you have? ";
                    cin >> eleccon[3][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of phone chargers
                    case 'P':
                    repeat = true;
                    cout << "How many phone chargers do you have? ";
                    cin >> eleccon[4][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of TVs
                    case 'T':
                    repeat = true;
                    cout << "How many TVs do you have? ";
                    cin >> eleccon[5][2];
                    TemporaryAntiInfinity ();
                break;

                case '+':
                    if (ToggleAMC == 0){
                        ToggleAM = true;
                        ToggleAMC = 1;
                        repeat = true;
                    } else if (ToggleAMC == 1){
                        ToggleAM = false;
                        ToggleAMC = 0;
                        repeat = true;
                    }
                break;

                //Give number of light bulbs
                    case 'I':
                    repeat = true;
                    cout << "How many light bulbs do you have? ";
                    cin >> eleccon[6][2];
                    TemporaryAntiInfinity ();
                break;
                //Give number of wifi routers
                    case 'R':
                    repeat = true;
                    cout << "How many wifi routers do you have? ";
                    cin >> eleccon[7][2];
                    TemporaryAntiInfinity ();
                break;
                //Give number of microwaves
                    case 'M':
                    repeat = true;
                    cout << "How many microwaves do you have? ";
                    cin >> eleccon[8][2];
                    TemporaryAntiInfinity ();
                break;
                //Give number of washing machines
                    case 'W':
                    repeat = true;
                    cout << "How many washing machines do you have? ";
                    cin >> eleccon[10][2];
                    TemporaryAntiInfinity ();
                break;
                //Give number of dryers
                    case 'D':
                    repeat = true;
                    cout << "How many dryers do you have? ";
                    cin >> eleccon[9][2];
                    TemporaryAntiInfinity ();
                break;
                    case 'H':
                        mode1 = true;
                        mode2 = false;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'J':
                        mode1 = false;
                        mode2 = true;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'K':
                        mode1 = false;
                        mode2 = false;
                        mode3 = true;
                        repeat = true;
                    break;

                                        //new new new new
                case 'F':
                    repeat = true;
                    cout << "How many Fridges do you have?" << endl;
                    cin >> eleccon[11][2];
                    TemporaryAntiInfinity ();
                break;

                case 'V':
                    repeat = true;
                    cout << "How many Rice Cookers do you have?" << endl;
                    cin >> eleccon[12][2];
                    TemporaryAntiInfinity ();
                break;

                case 'Y':
                    repeat = true;
                    cout << "How many Air Fryers do you have?" << endl;
                    cin >> eleccon[13][2];
                    TemporaryAntiInfinity ();
                break;

                case 'Z':
                    repeat = true;
                    cout << "How many Laptop Coolers do you have?" << endl;
                    cin >> eleccon[14][2];
                    TemporaryAntiInfinity ();
                break;
//break s s


                    //new new new new
                case 'f':
                    repeat = true;
                    cout << "How many Fridges do you have?" << endl;
                    cin >> eleccon[11][2];
                    TemporaryAntiInfinity ();
                break;

                case 'v':
                    repeat = true;
                    cout << "How many Rice Cookers do you have?" << endl;
                    cin >> eleccon[12][2];
                    TemporaryAntiInfinity ();
                break;

                case 'y':
                    repeat = true;
                    cout << "How many Air Fryers do you have?" << endl;
                    cin >> eleccon[13][2];
                    TemporaryAntiInfinity ();
                break;

                case 'z':
                    repeat = true;
                    cout << "How many Laptop Coolers do you have?" << endl;
                    cin >> eleccon[14][2];
                    TemporaryAntiInfinity ();
                break;



                    case 'e':
                    repeat = true;
                    cout << "How many fans do you have? ";
                    cin >> eleccon[0][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of aircons
                    case 'a':
                    repeat = true;
                    cout << "How many aircons do you have? ";
                    cin >> eleccon[1][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of laptop chargers
                    case 'l':
                    repeat = true;
                    cout << "How many laptop chargers do you have? ";
                    cin >> eleccon[2][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of desktop PC
                    case 'c':
                    repeat = true;
                    cout << "How many desktop PCs do you have? ";
                    cin >> eleccon[3][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of phone chargers
                    case 'p':
                    repeat = true;
                    cout << "How many phone chargers do you have? ";
                    cin >> eleccon[4][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of TVs
                    case 't':
                    repeat = true;
                    cout << "How many TVs do you have? ";
                    cin >> eleccon[5][2];
                    TemporaryAntiInfinity ();
                break;

                //Give number of light bulbs
                    case 'i':
                    repeat = true;
                    cout << "How many light bulbs do you have? ";
                    cin >> eleccon[6][2];
                    TemporaryAntiInfinity ();
                break;
                //Give number of wifi routers
                    case 'r':
                    repeat = true;
                    cout << "How many wifi routers do you have? ";
                    cin >> eleccon[7][2];
                    TemporaryAntiInfinity ();
                break;
                //Give number of microwaves
                    case 'm':
                    repeat = true;
                    cout << "How many microwaves do you have? ";
                    cin >> eleccon[8][2];
                    TemporaryAntiInfinity ();
                break;
                //Give number of washing machines
                    case 'w':
                    repeat = true;
                    cout << "How many washing machines do you have? ";
                    cin >> eleccon[10][2];
                    TemporaryAntiInfinity ();
                break;
                //Give number of dryers
                    case 'd':
                    repeat = true;
                    cout << "How many dryers do you have? ";
                    cin >> eleccon[9][2];
                    TemporaryAntiInfinity ();
                break;
                    case 'h':
                        mode1 = true;
                        mode2 = false;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'j':
                        mode1 = false;
                        mode2 = true;
                        mode3 = false;
                        repeat = true;
                    break;

                    case 'k':
                        mode1 = false;
                        mode2 = false;
                        mode3 = true;
                        repeat = true;
                    break;






                    default:
                    repeat = true;
                    cout << "INVALID INPUT, PLEASE TRY AGAIN" << endl;
                };

                }

         else if (decisionOM == 'E' || decisionOM == 'e'){
              //Program end
        }

        } while (repeat == true);


    return 0;

}


//Functions

void TemporaryAntiInfinity () {

                    if (cin.fail()){
                        cin.clear();
                        cin.ignore();

                    }
}
//Opening Menu
void OM (){
    cout << "*************************************************************************************************************" <<endl;
    cout << "*                                                                                                           *" <<endl;
    cout << "*                                   Energy Consumption Feedback Program                                     *" <<endl;
    cout << "*                                                                                                           *" <<endl;
    cout << "*************************************************************************************************************" <<endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
    cout << "EEEEEEEEEEEE                    CCCCCCCc                 FFFFFFFFFFFF                 PPPPPPP                " << endl;
    cout << "EE                             C      cc                 FF                           PP     PP              " << endl;
    cout << "EE                            C                          FF                           PP       PP            " << endl;
    cout << "EE                           Cc                          FF                           PP        PP           " << endl;
    cout << "EEEEEEEEEEEE                 Cc                          FFFFFFFFFFFF                 PP       PP            " << endl;
    cout << "EE                           Cc                          FF                           PP PPPPPP              " << endl;
    cout << "EE                            Cc                         FF                           PP                     " << endl;
    cout << "EE                             C       cc                FF                           PP                     " << endl;
    cout << "EEEEEEEEEEEE                    CCCCCCCc                 FF                           PP                     " << endl;
        cout << "" << endl;
        cout << "" << endl;
    cout << "                                   Type the letter and press enter" << endl;
        cout << "" << endl;
    cout << "                Press S to Start!                                        Press E to Exit!" << endl;
        cout << "" << endl;
}

//New Main Menu
void NMM ()
{
    cout << "****************************************************************************************" <<endl;
    cout << "*                                                                                      *" <<endl;
    cout << "*                           Energy Consumption Feedback Program                        *" <<endl;
    cout << "*                                                                                      *" <<endl;
    cout << "****************************************************************************************" <<endl;
    cout << endl;
    cout << "             Special Commands:" << endl;
    cout << "             = - Calculate          X - Clear all input          + - Advance Mode" << endl;
    cout << "             H - Toggle Hours Mode  J - Toggle Power Rating Mode K - Toggle Number Mode" << endl;
    cout << "             ? - Help Menu" << endl;
    cout << endl;
    cout << "             Appliances:" << endl;
    cout << "             E - Electric Fan       A - Aircon                   T - TV" << endl;
    cout << "             L - Laptop Charger     C - Desktop Computer         R - Wifi Router" << endl;
    cout << "             P - Phone Charger      I - Ilaw (Light Bulb)        M - Microwave" << endl;
    cout << endl;
    cout << "             W - Washing Machine    D - Dryer                    F - Fridge" << endl;
    cout << "             V - Rice Cooker        Y - Air Fryer                Z - Laptop Cooler" << endl;
    cout << "             U - Electric Kettle    Q - Radio                    O - Toaster" << endl;
    cout << "             S - Steam Iron" << endl;
    cout << endl;
    cout << "****************************************************************************************" << endl;
}


//CleanResetPostionForMenu
void MenuResetPosition ()
{
    for (int x = 0; x <= 30; x++){
        cout << "" << endl;
    }
}

//CleanResetPostionForMenu2
void MenuResetPosition2 ()
{
    for (int x = 0; x <= 5; x++){
        cout << "" << endl;
    }
}



//Help menu insutructions
void helpmenu ()
{
    char understanding;
    bool repeatunder = true;
    cout << endl;
    cout << " Guide to use the calculator" << endl;
    cout << endl;
    cout << " The 4 different modes" << endl;
    cout << endl;
    cout << " The 4 different modes include hour, power rating, numbers, and advance mode." << endl;
    cout << " You can use advance mode along any of the first 3 mentioned modes. You can only use one mode at a time" << endl;
    cout << endl;


    cout << " Toggle Hour Mode" << endl;
    cout << endl;
    cout << " This mode enables you to modify the amount of hours you used for a specific device." << endl;
    cout << " By default all values are set to 0." << endl;
    cout << endl;

    cout << " Toggle Power Rating Mode" << endl;
    cout << endl;
    cout << " This mode allows you to change the power rating or hourly wattage of a specific device." << endl;
    cout << " By default, all values are set to an average number given by Google" << endl;
    cout << endl;

    cout << " Toggle Number Mode" << endl;
    cout << endl;
    cout << " This mode allows you to change the number of specific appliances you have." << endl;
    cout << " By default, all values are set to 1." << endl;

    cout << endl;

    cout << " Advance Mode" << endl;
    cout << endl;
    cout << " This mode can be used alongside hour, power rating, and number mode. This mode allows you " << endl;
    cout << " to view the hour, power rating, and number values of all appliances in the menu in the" << endl;
    cout << " same time. The values update every time you change something. Please keep in mind that" << endl;
    cout << " the way you use advance mode is the same as normal mode. The only difference is you get" << endl;
    cout << " to see what values each appliance have while your editing them." << endl;
    cout << endl;



        while (repeatunder == true)
        {
            repeatunder = false;
            cout << "Do you understand the program? (y/n) ";
            cin >> understanding;
            if (understanding == 'y'){
                cout << "Going back to main menu..." << endl;
            } else if (understanding == 'n'){
                cout << endl;
                cout << "Please contact support about your concern, thank you!" << endl;
            } else {
                cout << "Invalid input, please try again" << endl;
                repeatunder = true;
            }
        }

}
