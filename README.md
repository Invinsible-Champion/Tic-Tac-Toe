# 🤖 AI Tic Tac Toe 🤖

A  Tic Tac Toe game featuring a smart AI opponent powered by a high-performance C++ backend using the [Crow](https://github.com/CrowCpp/Crow) microservice framework and the Minimax algorithm.

---

## Backend Implementation

The AI logic is implemented in C++ using the Minimax algorithm to provide optimal moves. The backend runs as a lightweight HTTP API server built with [Crow](https://github.com/CrowCpp/Crow), offering endpoints to:

- Evaluate the current board state
- Return the best next move for the AI

This separation ensures fast, efficient AI computations while keeping the frontend responsive and visually engaging.

---

## Frontend Integration

The frontend is a responsive web app built with HTML, CSS, and JavaScript. It communicates with the backend API via HTTP requests to:

- Send the current board state for evaluation
- Retrieve the AI’s best move

Fallback logic and random move selection are implemented to handle API failures gracefully, ensuring smooth gameplay.

---

## Installation and Setup Guide

### Prerequisites

- Modern web browser (Chrome, Firefox, Safari, Edge)
- C++ compiler supporting C++11 or higher (for building the backend)
- CMake (recommended for building the backend)
- Python 3 (optional, for serving frontend locally)

### Backend Setup

1. Clone the backend repository (or your project root if combined):

   ```bash
   git clone https://github.com/Invinsible-Champion/Tic-Tac-Toe.git
   cd Tic-Tac-Toe

 2. Build the backend using:
   ```bash
     mkdir build
     cd build
     cmake ..
     make  
   ```
3. Run the server using 
  ```bash
     ./server
```

