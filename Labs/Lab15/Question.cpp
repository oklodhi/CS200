#include <iostream>
#include "Question.h"
using namespace std;

void QuestionBase::Display(){
    cout << m_questionText << endl;
}


void QuestionBase::SetQuestionText(const string& text){
    m_questionText = text;
}

void TrueFalseQuestion::Display(){
    QuestionBase::Display();
    cout << "*true* OR *false*" << endl;
}

void TrueFalseQuestion::SetCorrectAnswer(const string& correctAnswer){
    m_questionText = correctAnswer;
}

bool TrueFalseQuestion::CheckAnswer(const string& userAnswer){
    if (m_correctAnswer == userAnswer) {
        return true;
    } else {
        return false;
    }
}

void MultipleChoiceQuestion::Display(){
    QuestionBase::Display();
    for (int i = 0; i < 4; i++) {
        cout << i << ". " << m_answers[i] << endl;
    }
}

void MultipleChoiceQuestion::SetCorrectAnswer(int correctAnswer){
    m_questionText = correctAnswer;
}

bool MultipleChoiceQuestion::CheckAnswer(int userAnswer){
    if (userAnswer == 0){
        return true;
    } else if (userAnswer == 1){
        return true;
    } else if (userAnswer == 2){
        return true;
    } else if (userAnswer == 3){
        return true;
    } else {
        return false;
    }
}

void MultipleChoiceQuestion::SetAnswerChoices(const string& a0, const string& a1, const string& a2, const string& a3){
    m_answers[0] = a0;
    m_answers[1] = a1;
    m_answers[2] = a2;
    m_answers[3] = a3;
}
