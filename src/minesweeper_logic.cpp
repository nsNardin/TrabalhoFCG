#include <stdexcept>
#include <random>
#include <ctime>

class Block {
public:
	bool bomb;
	int bomb_counter;
	bool revealed;
	bool flag;
};

class Board {
private:
	static const int WIDTH = 10;
	static const int HEIGHT = 10;
	Block board_[WIDTH][HEIGHT] = {};
public:
	/// Returns a reference to the block at the given coordinates.
	///
	/// If the coordinates are out of bounds, the behavior is undefined.
	Block& at(int x, int y) { return board_[x][y]; }

	/// Returns a const reference to the block at the given coordinates.
	///
	/// If the coordinates are out of bounds, the behavior is undefined.
	const Block& at(int x, int y) const { return board_[x][y]; }

	/// Initializes the board.
	///
	/// At the moment, this just initializes all blocks to be non-bombs with
	/// no flags and no revealed blocks.
	void init() {
		for (int x = 0; x < WIDTH; ++x) {
			for (int y = 0; y < HEIGHT; ++y) {
				board_[x][y] = {};
			}
		}
	}

    /// Place a bomb at the given coordinates.
    /// Increment the counter of nearby blocks.
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
                if (x + dx < 0 || x + dx >= WIDTH || y + dy < 0 || y + dy >= HEIGHT) {
                    continue;
                }
                ++board_[x + dx][y + dy].bomb_counter;
            }
        }
    }

    // Populate the board with n bombs randomly.
    void populate(int n) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist_x(0, WIDTH - 1);
        std::uniform_int_distribution<int> dist_y(0, HEIGHT - 1);
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

    // Reveal a block
    void reveal(int x, int y) {
        board_[x][y].revealed = true;
        // If the block is a bomb, game over
        if (board_[x][y].bomb) {}
        // Elif the counter is zero, recursively reveal all adjacent blocks
        else if (board_[x][y].bomb_counter == 0) {
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) {
                        continue;
                    }
                    if (x + dx < 0 || x + dx >= WIDTH || y + dy < 0 || y + dy >= HEIGHT) {
                        continue;
                    }
                    reveal(x + dx, y + dy);
                }
            }
        }
    }

    // Check for victory
    bool checkVictory() {
        for (int x = 0; x < WIDTH; ++x) {
            for (int y = 0; y < HEIGHT; ++y) {
                if (!board_[x][y].revealed && !board_[x][y].bomb) {
                    return false;
                }
            }
        }
        return true;
    }

    // Toggle flag
    void toggleFlag(int x, int y) {
        board_[x][y].flag = !board_[x][y].flag;
    }

    // Try to reveal
    void tryReveal(int x, int y) {
        if (!board_[x][y].revealed && !board_[x][y].flag) {
            reveal(x, y);
        }
    }

};

