#ifndef SIMPLEGOMOKUAI_H
#define SIMPLEGOMOKUAI_H

#include <vector>
#include <utility>
#include<string>

class AI {
public:
    AI();
    void setDifficulty(int diff);
    std::pair<int,int> getBestMove(const std::vector<std::vector<int>>& board, bool aiIsWhite);
    static void clear();
private:
    static constexpr int WIN_SCORE = 100000;
    static constexpr int INF = 999999;
    int maxDepth{};
    int maxCandidates{};
    static int patternScore(const std::string& pat) ;
    static int evaluatePatternsAt(const std::vector<std::vector<int>>& board, int row, int col, int piece) ;
    static std::string linePattern(const std::vector<std::vector<int>>& board, int row, int col, int dr, int dc, int piece) ;
    static int evaluateBoard(const std::vector<std::vector<int>>& board, bool aiIsWhite);
    static int positionScore(const std::vector<std::vector<int>>& board, int piece) ;
    [[nodiscard]] std::vector<std::pair<int,int>> getCandidates(const std::vector<std::vector<int>>& board) const;
    static int scoreCandidate(const std::vector<std::vector<int>>& board, int row, int col);
    static bool hasNearby(const std::vector<std::vector<int>>& board, int row, int col, int dist);
    static bool isWinAt(const std::vector<std::vector<int>>& board, int row, int col, int piece) ;
    static std::pair<int,int> findImmediateWin(const std::vector<std::vector<int>>& board, int piece) ;
    int dfs(std::vector<std::vector<int>>& board, int depth, int alpha, int beta, bool isAiTurn, bool aiIsWhite,
        int& bestRow, int& bestCol);
    static void doMove(std::vector<std::vector<int>>& board, int row, int col, int piece);
    static void undoMove(std::vector<std::vector<int>>& board, int row, int col);
};
#endif // SIMPLEGOMOKUAI_H