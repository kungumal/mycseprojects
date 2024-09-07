questions = [
    {
        "prompt": "What is the capital of France?",
        "option": ["A. Paris", "B. London", "C. Berlin", "D. Madrid"],
        "answer": "A"
    },
    {
        "prompt": "Which language is primarily spoken in Brazil?",
        "option": ["A. Spanish", "B. Portuguese", "C. English", "D. French"],
        "answer": "B"
    },
    {
        "prompt": "What is the smallest prime number?",
        "option": ["A. 1", "B. 2", "C. 3", "D. 5"],
        "answer": "B"
    },
    {
        "prompt": "Who wrote 'To Kill a Mockingbird'?",
        "option": ["A. Harper Lee", "B. Mark Twain", "C. J.K. Rowling", "D. Ernest Hemingway"],
        "answer": "A"
    }
]

def run_quiz(questions):
    score = 0
    for question in questions:
        print(question["prompt"])
        for option in question["option"]:
            print(option)
        answer = input("Enter your answer (A, B, C, or D): ").upper()  # Ensuring input is uppercase
        if answer == question["answer"]:
            print("Correct, hooray!!\n")
            score += 1
        else:
            print("Wrong! The correct answer was", question["answer"], "\n")
    
    print(f"You got {score} out of {len(questions)} correct.")

# Run the quiz
run_quiz(questions)
