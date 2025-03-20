#include "MainForm.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

MainForm::MainForm(void) {
    InitializeComponent();
}

void MainForm::InitializeComponent(void) {
    this->labelMessage = gcnew Label();
    this->buttonClickMe = gcnew Button();
    this->textBoxInput = gcnew TextBox();

    this->SuspendLayout();

    // labelMessage
    this->labelMessage->Location = System::Drawing::Point(20, 20);
    this->labelMessage->Size = System::Drawing::Size(200, 30); // ����������
    this->labelMessage->Text = "������� �����:";

    // textBoxInput
    this->textBoxInput->Location = System::Drawing::Point(20, 60);
    this->textBoxInput->Size = System::Drawing::Size(200, 20); // ����������

    // buttonClickMe
    this->buttonClickMe->Location = System::Drawing::Point(20, 100);
    this->buttonClickMe->Size = System::Drawing::Size(200, 30); // ����������
    this->buttonClickMe->Text = "����� ����!";
    this->buttonClickMe->Click += gcnew EventHandler(this, &MainForm::buttonClickMe_Click);

    // MainForm
    this->ClientSize = System::Drawing::Size(250, 150); // ����������
    this->Controls->Add(this->labelMessage);
    this->Controls->Add(this->textBoxInput);
    this->Controls->Add(this->buttonClickMe);
    this->Text = "��� ����������";

    this->ResumeLayout(false);
}

void MainForm::buttonClickMe_Click(Object^ sender, EventArgs^ e) {
    String^ inputText = textBoxInput->Text;
    if (!String::IsNullOrEmpty(inputText)) {
        MessageBox::Show("�� �����: " + inputText, "���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else {
        MessageBox::Show("����������, ������� �����!", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

[STAThread]
int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MainForm());
    return 0;
}