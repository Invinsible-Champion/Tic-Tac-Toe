#include <bits/stdc++.h>
#include "crow.h"
#include "board_middleware.h"
#include "logic.h"

using namespace std;


struct CorsMiddleware
{
    struct context
    {
    };

    void before_handle(crow::request &, crow::response &, context &)
    {
        
    }

    void after_handle(crow::request &, crow::response &res, context &)
    {
        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.add_header("Access-Control-Allow-Headers", "Content-Type");
    }
};

int main()
{
    crow::App<CorsMiddleware> app;

    // Root route
    CROW_ROUTE(app, "/").methods("GET"_method, "OPTIONS"_method)([](const crow::request &req)
                                                                 {
        if (req.method == crow::HTTPMethod::OPTIONS)
        {
            
            return crow::response(204);
        }
        return crow::response("API is up and running!"); });

    CROW_ROUTE(app, "/evaluate_board").methods("POST"_method, "OPTIONS"_method)([](const crow::request &req)
                                                                                {
        if (req.method == crow::HTTPMethod::OPTIONS)
            return crow::response(204);

        auto json = crow::json::load(req.body);
        if (!json || !json.has("Board"))
            return crow::response(400, "Invalid JSON");

        Board board;
        auto input_board = json["Board"];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board.board[i][j] = input_board[i][j].i();

        if (!board.is_valid_board())
            return crow::response(400, "Invalid Board State!");

        int eval = board.evaluate_board();
        crow::json::wvalue result;
        result["evaluation"] = eval;
        return crow::response(result); });


    CROW_ROUTE(app, "/get_best_move").methods("POST"_method, "OPTIONS"_method)([](const crow::request &req)
                                                                               {
        if (req.method == crow::HTTPMethod::OPTIONS)
            return crow::response(204);

        auto json = crow::json::load(req.body);
        if (!json || !json.has("Board") || !json.has("Player") || json["Player"].t() != crow::json::type::Number)
            return crow::response(400, "Invalid JSON");

        Board board;
        auto input_board = json["Board"];
        int player = json["Player"].i();

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board.board[i][j] = input_board[i][j].i();

        if (!board.is_valid_board())
            return crow::response(400, "Invalid Board State!");

        auto move = get_best_move(board, player);
        if (move.first == -1 || move.second == -1)
            return crow::response(400, "Board has likely reached terminal_state!");

        crow::json::wvalue result;
        result["row"] = move.first;
        result["col"] = move.second;
        return crow::response(result); });

    app.port(9000).multithreaded().run();
}
