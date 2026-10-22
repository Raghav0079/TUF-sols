class SnakeGame {
    int width, height;
    vector<vector<int>> food;
    int foodPos;
    deque<pair<int, int>> snake;
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->width = width;
        this->height = height;
        this->food = food;
        foodPos = 0;
        snake.push_front({0, 0}); 
    }
    int move(string direction) {
        int i = snake.front().first;
        int j = snake.front().second;

        if (direction == "U") i--;
        else if (direction == "D") i++;
        else if (direction == "L") j--;
        else if (direction == "R") j++;

        // Check if the snake hits the boundary
        if (i < 0 || i >= height || j < 0 || j >= width) return -1;

        pair<int, int> newHead = {i, j};

        if (find(snake.begin(), snake.end(), newHead) != snake.end()
        && newHead != snake.back()) 
            return -1;

        if (foodPos < food.size() && i == food[foodPos][0]
        && j == food[foodPos][1]) {
            foodPos++;
        } 
        // Remove the last part of the snake
        else {
            
            snake.pop_back();
        }
        // Add the new head position to the front
        snake.push_front(newHead);

        return foodPos;
    }
};



int main() {
    vector<vector<int>> food = {{1, 2}, {0, 1}};
    SnakeGame game(3, 3, food);
    cout << game.move("R") << endl;  
    cout << game.move("D") << endl;  
    cout << game.move("R") << endl;  
    cout << game.move("U") << endl;  
    cout << game.move("L") << endl; 
    cout << game.move("U") << endl; 
    return 0;
}

