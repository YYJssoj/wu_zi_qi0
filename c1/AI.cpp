#include "AI.h"

#include <algorithm>
#include <cmath>
#include <string>
#include"mainai.h"
static const std::vector<std::pair<int,int>> DIRECTIONS = {{0,1},{1,0},{1,1},{1,-1}};
AI::AI() {setDifficulty(2);}
void AI::setDifficulty(const int diff) {
    if (diff == 2) {
        maxDepth = 6;
        maxCandidates = 12;
    }
    else {
        maxDepth = 4;
        maxCandidates = 8;
    }
}
void AI::clear() {}
int AI::patternScore(const std::string& pat) {
    if (pat.find("11111") != std::string::npos) {return 100000;}
    if (pat.find("011110") != std::string::npos) {return 10000;}
    if (pat.find("11110") != std::string::npos || pat.find("01111") != std::string::npos){return 4000;}
    if(pat.find("11011") != std::string::npos || pat.find("11101") != std::string::npos ||
        pat.find("10111") != std::string::npos) {return 2500;}
    if (pat.find("01110") != std::string::npos || pat.find("011010") != std::string::npos ||
        pat.find("010110") != std::string::npos) {return 2000;}
    if (pat.find("11100") != std::string::npos || pat.find("00111") != std::string::npos ||
        pat.find("11010") != std::string::npos || pat.find("01011") != std::string::npos ||
        pat.find("10110") != std::string::npos) {return 1500;}
    if (pat.find("01100") != std::string::npos || pat.find("00110") != std::string::npos ||
        pat.find("01010") != std::string::npos) {return 100;}
    if (pat.find("11000") != std::string::npos || pat.find("00011") != std::string::npos ||
        pat.find("10100") != std::string::npos || pat.find("00101") != std::string::npos) {return 20;}
    if (pat.find("01000") != std::string::npos || pat.find("00010") != std::string::npos ||
        pat.find("00100") != std::string::npos) {return 5;}
    return 0;
}
int AI::evaluatePatternsAt(const std::vector<std::vector<int>>& board, const int row, const int col, const int piece) {
    int total = 0;
    for (const auto&[fst, snd] : DIRECTIONS) {
        std::string pattern = linePattern(board, row, col, fst, snd, piece);
        total += patternScore(pattern);
    }
    return total;
}
std::string AI::linePattern(const std::vector<std::vector<int>>& board, const int row, const int col, const int dr, const int dc, const int piece) {
    std::string pat;
    for (int k = -4; k <= 4; ++k) {
        const int r = row + k * dr;
        if (const int c = col + k * dc; r < 0 || r >= 15 || c < 0 || c >= 15) {pat += 'X';}
        else if (board[r][c] == piece) {pat += '1';}
        else if (board[r][c] == 0) {pat += '0';}
        else {pat += 'X';}
    }
    return pat;
}
int AI::evaluateBoard(const std::vector<std::vector<int>>& board, const bool aiIsWhite) {
    int aiScore = 0, playerScore = 0;
    const int aiPiece = aiIsWhite ? 2 : 1;
    const int playerPiece = aiIsWhite ? 1 : 2;
    for (int i=0;i<15;i++) {
        for (int j=0;j<15;j++) {
            if (board[i][j]==aiPiece){aiScore += evaluatePatternsAt(board, i, j, aiPiece);}
            else if (board[i][j]==playerPiece){playerScore += evaluatePatternsAt(board, i, j, playerPiece);}
        }
    }
    aiScore += positionScore(board, aiPiece);
    playerScore += positionScore(board, playerPiece);
    return static_cast<int>(std::round(1.15*aiScore-playerScore));
}
int AI::positionScore(const std::vector<std::vector<int>>& board, const int piece) {
    constexpr int center = 15 / 2;
    int score = 0;
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (board[i][j] == piece) {
                const int d = std::abs(i - center) + std::abs(j - center);
                score += std::max(0, 10 - d);
                if (i == 0 || i == 15-1 || j == 0 || j == 15-1) score -= 5;
            }
        }
    }
    return score;
}
bool AI::hasNearby(const std::vector<std::vector<int>>& board, const int row, const int col, int dist) {
    const int r0 = std::max(0, row - dist);
    const int r1 = std::min(15-1, row + dist);
    const int c0 = std::max(0, col - dist);
    const int c1 = std::min(15-1, col + dist);
    for (int i = r0; i <= r1; ++i) {
        for (int j = c0; j <= c1; ++j) {
            if ((i != row || j != col) && board[i][j] != 0)
                return true;
        }
    }
    return false;
}
int AI::scoreCandidate(const std::vector<std::vector<int>>& board, const int row, const int col) {
    constexpr int center = 15 / 2;
    const int dist = std::abs(row - center) + std::abs(col - center);
    int score = std::max(0, 12 - dist);
    auto boardCopy = board;
    boardCopy[row][col] = 2;
    score += evaluatePatternsAt(boardCopy, row, col, 2);
    boardCopy[row][col] = 1;
    score += evaluatePatternsAt(boardCopy, row, col, 1);
    return score;
}

std::vector<std::pair<int,int>> AI::getCandidates(const std::vector<std::vector<int>>& board) const {
    struct Candidate {
        int row, col, score;
    };
    std::vector<Candidate> cands;
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (board[i][j] == 0 && hasNearby(board, i, j, 1)) {
                cands.push_back({i, j, scoreCandidate(board, i, j)});
            }
        }
    }
    std::sort(cands.begin(), cands.end(), [](const Candidate& a, const Candidate& b) {
        return a.score > b.score;
    });
    std::vector<std::pair<int,int>> result;
    const int lim=std::min(static_cast<int>(cands.size()), maxCandidates);
    result.reserve(lim);
for (int i=0;i<lim;++i){result.emplace_back(cands[i].row, cands[i].col);}
    return result;
}
bool AI::isWinAt(const std::vector<std::vector<int>>& board, const int row, const int col, const int piece) {
    for (const auto&[fst, snd] : DIRECTIONS) {
        int count = 1;
        const int dr=fst;
        const int dc=snd;
        for (int r=row+dr,c=col+dc; r>=0 && r<15 && c>=0 && c<15 && board[r][c]==piece; r+=dr, c+=dc) {count++;}
        for (int r=row-dr,c=col-dc; r>=0 && r<15 && c>=0 && c<15 && board[r][c]==piece; r-=dr, c-=dc) {count++;}
        if (count >= 5) {return true;}
    }
    return false;
}
std::pair<int,int> AI::findImmediateWin(const std::vector<std::vector<int>>& board, const int piece) {
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (board[i][j] != 0) {continue;}
            auto boardCopy = board;
            boardCopy[i][j]=piece;
            if (isWinAt(boardCopy, i, j, piece))return {i, j};
        }
    }
    return {-1, -1};
}

int AI::dfs(std::vector<std::vector<int>>& board, const int depth, int alpha, int beta, const bool isAiTurn, const bool aiIsWhite, int& bestRow, int& bestCol) {
    if (depth==0) {return evaluateBoard(board, aiIsWhite);}
    auto candidates = getCandidates(board);
    if (candidates.empty()) {return 0;}
    const int currentPiece=isAiTurn ? (aiIsWhite ? 2 : 1) : aiIsWhite ? 1 : 2;
    if (isAiTurn) {
        int maxEval = -INF;
        for (const auto&[fst, snd] : candidates) {
            const int row = fst;
            const int col = snd;
            doMove(board, row, col, currentPiece);
            if (isWinAt(board, row, col, currentPiece)) {
                undoMove(board, row, col);
                bestRow = row; bestCol = col;
                return WIN_SCORE;
            }
            int eval = dfs(board, depth - 1, alpha, beta, false, aiIsWhite, bestRow, bestCol);
            undoMove(board, row, col);
            if (eval > maxEval) {
                maxEval = eval;
                if (depth == maxDepth) {
                    bestRow = row;
                    bestCol = col;
                }
            }
            alpha = std::max(alpha, eval);
            if (beta <= alpha) {break;}
            if (maxEval >= WIN_SCORE) {break;}
        }
        return maxEval;
    }
    int minEval = INF;
    for (const auto&[fst, snd] : candidates) {
        const int row = fst;
        const int col = snd;
        doMove(board, row, col, currentPiece);
        if (isWinAt(board, row, col, currentPiece)) {
            undoMove(board, row, col);
            return -WIN_SCORE;
        }
        int eval = dfs(board, depth - 1, alpha, beta, true, aiIsWhite, bestRow, bestCol);
        undoMove(board, row, col);
        if (eval < minEval) {minEval = eval;}
        beta = std::min(beta, eval);
        if (beta <= alpha) break;
        if (minEval <= -WIN_SCORE) break;
    }
    return minEval;
}
void AI::doMove(std::vector<std::vector<int>>& board, const int row, const int col, const int piece) {
    board[row][col] = piece;
}
void AI::undoMove(std::vector<std::vector<int>>& board, const int row, const int col) {
    board[row][col] = 0;
}
std::pair<int,int> AI::getBestMove(const std::vector<std::vector<int>>& board, const bool aiIsWhite) {
    if (auto winMove = findImmediateWin(board, aiIsWhite ? 2 : 1); winMove.first != -1) return winMove;
    if (auto playerWinMove = findImmediateWin(board, aiIsWhite ? 1 : 2); playerWinMove.first != -1) return playerWinMove;
    std::vector<std::vector<int>> boardCopy = board;
    int bestRow = -1, bestCol = -1;
    const int depth = maxDepth;
    dfs(boardCopy, depth, -INF, INF, true, aiIsWhite, bestRow, bestCol);
    if (bestRow != -1) return {bestRow, bestCol};
    if (auto candidates = getCandidates(board); !candidates.empty()) return candidates[0];
    return {15/2, 15/2};
}