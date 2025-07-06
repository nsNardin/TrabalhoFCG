#include <stdexcept>
#include <random>
#include <vector>

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 10;
const int BOMB_COUNTER = 6;

class Block {
public:
    bool bomb;
    int bomb_counter;
    bool revealed;
    bool flag;
};

enum class GameState {
    UNSTARTED,
    RUNNING,
    VICTORY,
    DEFEAT
};

class Board {
private:
    Block board_[BOARD_WIDTH][BOARD_HEIGHT] = {};
    GameState state_ = GameState::UNSTARTED;

    // Place a bomb at the given coordinates.
    // Increment the counter of nearby blocks.
    void placeBomb(int x, int y) {
        if (board_[x][y].bomb) {
            throw std::runtime_error("Cannot place a bomb on a block that already has a bomb");
        }
        board_[x][y].bomb = true;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) {
                    continue;
                }
                if (x + dx < 0 || x + dx >= BOARD_WIDTH || y + dy < 0 || y + dy >= BOARD_HEIGHT) {
                    continue;
                }
                ++board_[x + dx][y + dy].bomb_counter;
            }
        }
    }

    // Reveal a block
    /*void reveal(int x, int y) {
        board_[x][y].revealed = true;
        // If the block is a bomb, game over
        if (board_[x][y].bomb) {
            state_ = GameState::DEFEAT;
        }
        // Elif the counter is zero, recursively reveal all adjacent blocks
        else if (board_[x][y].bomb_counter == 0) {
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) {
                        continue;
                    }
                    if (x + dx < 0 || x + dx >= BOARD_WIDTH || y + dy < 0 || y + dy >= BOARD_HEIGHT) {
                        continue;
                    }
                    reveal(x + dx, y + dy);
                }
            }
        }
    }*/
   void reveal(int x, int y) {
        if (board_[x][y].revealed || board_[x][y].flag) {
            return; // evita revelações repetidas ou em blocos com bandeira
        }

        board_[x][y].revealed = true;

        if (board_[x][y].bomb) {
            state_ = GameState::DEFEAT;
        } else if (board_[x][y].bomb_counter == 0) {
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < BOARD_WIDTH && ny >= 0 && ny < BOARD_HEIGHT) {
                        reveal(nx, ny);
                    }
                }
            }
        }
    }

    // Check for victory
    bool checkVictory() {
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            for (int y = 0; y < BOARD_HEIGHT; ++y) {
                if (!board_[x][y].revealed && !board_[x][y].bomb) {
                    return false;
                }
            }
        }
        return true;
    }

    // Populate the board with n bombs randomly.
    void populate(int n) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist_x(0, BOARD_WIDTH - 1);
        std::uniform_int_distribution<int> dist_y(0, BOARD_HEIGHT - 1);
        int placed = 0;
        while (placed < n) {
            int x = dist_x(mt);
            int y = dist_y(mt);
            try {
                placeBomb(x, y);
                ++placed;
            } catch (const std::runtime_error&) {
                // Ignore and try placing the bomb again
            }
        }
    }

public:
    // Returns a const reference to the block at the given coordinates.
    const Block& getBlock(int x, int y) const {
        return board_[x][y];
    }
    
    // Returns the current game state
    const GameState& getState() const {
        return state_;
    }

    // Initializes the board.
    void init() {
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            for (int y = 0; y < BOARD_HEIGHT; ++y) {
                board_[x][y] = {};
            }
        }
    }

    // Toggle flag
    void toggleFlag(int x, int y) {
        board_[x][y].flag = !board_[x][y].flag;
    }

    // Try to reveal
    void tryReveal(int x, int y) {
        if (!board_[x][y].revealed && !board_[x][y].flag) {
            reveal(x, y);
            if (checkVictory()) {
                state_ = GameState::VICTORY;
            }
        }
    }

    // Starts the game
    void start() {
        populate(BOMB_COUNTER);
        state_ = GameState::RUNNING;
    }
};

