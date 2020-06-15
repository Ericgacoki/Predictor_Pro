
#include <iostream>
#include <cmath>
#inclu

using namespace std;

int main() {

    /*  collect  the data-set used to train our Predictor  */

    float Mid_Score[5], End_Score[5];
    cout << "The system needs 5 pairs of initial/training values" << endl;

    for (int length = 0; length <= 4; length++) {

        cout << "Enter Mid score value " << length + 1 << ": -> ";

        cin.ignore();
        cin >> Mid_Score[length];

        cout << "Enter " << Mid_Score[length] << "'s corresponding value: -> ";
        cin  >> End_Score[length];
    }


    float Mid_Score_Squared[5] = {float(pow(Mid_Score[0], 2)),
                                  float(pow(Mid_Score[1], 2)),
                                  float(pow(Mid_Score[2], 2)),
                                  float(pow(Mid_Score[3], 2)),
                                  float(pow(Mid_Score[4], 2))};

    float Mid_Times_End[5] = {(Mid_Score[0] * End_Score[0]),
                              (Mid_Score[1] * End_Score[1]),
                              (Mid_Score[2] * End_Score[2]),
                              (Mid_Score[3] * End_Score[3]),
                              (Mid_Score[4] * End_Score[4])};

    float Total_mid = ((Mid_Score[0]) + (Mid_Score[1]) + (Mid_Score[2]) + (Mid_Score[3]) + (Mid_Score[4]));
    float Total_End = ((End_Score[0]) + (End_Score[1]) + (End_Score[2]) + (End_Score[3]) + (End_Score[4]));

    float Total_Mid_Squared = (Mid_Score_Squared[0]
                               + Mid_Score_Squared[1]
                               + Mid_Score_Squared[2]
                               + Mid_Score_Squared[3]
                               + Mid_Score_Squared[4]
    );

    float Total_Mid_Times_End = ((Mid_Times_End[0]
                                  + Mid_Times_End[1]
                                  + Mid_Times_End[2]
                                  + Mid_Times_End[3]
                                  + Mid_Times_End[4]
    ));

    float B, A;
    float B_numerator, B_denominator;

    B_numerator = (5 * (Total_Mid_Times_End) - (Total_mid * Total_End));
    B_denominator = (5 * Total_Mid_Squared) - (Total_mid * Total_mid);

    /* The above two equations couldn't be combined into one equation since C++ compiler interprets it differently
* and therefore gives wrong answers    */

    B = B_numerator /
        /*          __________________                                             */
        B_denominator;

    A = (Total_End - (B * Total_mid))
        /*         __________________________________                                    */
        / 5;

    float Mid_Score_Predict;
    /** The value whose End score is not known */

    for (int trial = 1; trial <= 5; trial++) {
        cout << endl << "Enter a Value to predict the End Score : ";
        cin >> Mid_Score_Predict;
        float Predicted_Score;
        /** validate inputs and perform final computation */

        if ((Mid_Score_Predict <= 100) && (Mid_Score_Predict > -1)) {
            Predicted_Score = A + (B * Mid_Score_Predict);

            cout << "Mid Score = " << Mid_Score_Predict << endl;
            cout << "A = " << A << endl << "B = " << B << endl << "Predicted Score = " << Predicted_Score << endl;
        } else {
            cout << "Invalid input . Please Try again" << endl;
        }
    }
    return 0;

    // GIVING STRENGTH TO COMRADES
}
