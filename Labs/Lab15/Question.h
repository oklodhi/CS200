#ifndef QUESTION_H_INCLUDED
#define QUESTION_H_INCLUDED
#include <string>
using namespace std;

class QuestionBase {
    protected:
        string m_questionText;

    public:
        void Display();
        void SetQuestionText(const string& text);
};

class TrueFalseQuestion : public QuestionBase {
    private:
        string m_correctAnswer;

    public:
        void Display();
        bool CheckAnswer(const string& userAnswer);
        void SetCorrectAnswer(const string& correctAnswer);
};

class MultipleChoiceQuestion : public QuestionBase {
    private:
        int m_correctAnswer;
        string m_answers[4];

    public:
        void Display();
        bool CheckAnswer(int userAnswer);
        void SetCorrectAnswer(int correctAnswer);
        void SetAnswerChoices(const string& a0, const string& a1, const string& a2, const string& a3);

};

#endif // QUESTION_H_INCLUDED
