#ifndef QUESTION_H_INCLUDED
#define QUESTION_H_INCLUDED

class QuestionBase() {
    protected string m_questionText;

    public:
        void display();
        void setQuestionText(const string& text);
};

#endif // QUESTION_H_INCLUDED
