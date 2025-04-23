#include"pch"


enum Color { RED, YELLOW, GREEN };

/*
move the red balls to begining
mover the green balls to the end
*/

void moveColorToStart(vector<Color>& balls, Color target) 
{
    int beginBallIndex = 0;
    for (int i = 0; i < balls.size(); ++i) 
    {
        if (balls[i] == target) 
        {
            swap(balls[i], balls[beginBallIndex]);
            ++beginBallIndex;
        }
    }
}

void moveColorToEnd(vector<Color>& balls, Color target) {
    int lastBasllIndex = balls.size() - 1;
    for (int i = balls.size() - 1; i >= 0; --i) {
        if (balls[i] == target) 
        {
            swap(balls[i], balls[lastBasllIndex]);
            --lastBasllIndex;
        }
    }
}

void sortBalls(vector<Color>& balls) 
{
    //moveColorToStart(balls, RED);
    //moveColorToEnd(balls, GREEN); 

    //case for 3 items
    //with o1 memory
    vector<Color> v(balls.size(), YELLOW);
    int start = 0;
    int end = v.size() - 1;
    for (Color ball : balls) 
    {
        if (ball == RED) v[start++] = RED;
        else if(ball == GREEN) v[end--] = GREEN;
    }

    balls = v;
}

void printBalls(const vector<Color>& balls) {
    for (Color ball : balls) {
        if (ball == RED) cout << "R ";
        else if (ball == YELLOW) cout << "Y ";
        else cout << "G ";
    }
    cout << endl;
}