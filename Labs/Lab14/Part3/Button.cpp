#include "Button.h"

void Button::SetText( string text )
{
    m_text = text;
}

void Button::Draw() const
{
    for (int i = 0; i < m_text.size() + 5; i++) {
        cout << "*";
    }

    cout << "\n* " << m_text << " *\n";

    for (int i = 0; i < m_text.size() + 5; i++) {
        cout << "*";
    }

    cout << endl;
}
