#pragma once

#include <windows.h>
#include <string>
#include <vector>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing; // Подключение пространства имен для Size

public ref class MainForm : public Form {
public:
    MainForm(void);

private:
    Label^ labelMessage;
    Button^ buttonClickMe;
    TextBox^ textBoxInput;

    void InitializeComponent(void);
    void buttonClickMe_Click(Object^ sender, EventArgs^ e);
};