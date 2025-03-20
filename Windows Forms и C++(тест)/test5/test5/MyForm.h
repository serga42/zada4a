#pragma once

#include <sqlite3.h>
#include <iostream>
#include <string>
#include <vector>

namespace MyProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();

            // Подключение к базе данных (или создание, если не существует)
            int rc = sqlite3_open("products.db", &db);
            if (rc) {
                MessageBox::Show(String::Format("Не удалось открыть базу данных: {0}", gcnew String(sqlite3_errmsg(db))), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }
            Console::WriteLine("База данных открыта.");

            // Создание таблицы Products (если ее нет)
            const char* sqlCreateTable =
                "CREATE TABLE IF NOT EXISTS Products ("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "name TEXT NOT NULL,"
                "description TEXT,"
                "price REAL"
                ");";

            rc = sqlite3_exec(db, sqlCreateTable, 0, 0, &zErrMsg);
            if (rc != SQLITE_OK) {
                MessageBox::Show(String::Format("Ошибка при создании таблицы: {0}", gcnew String(zErrMsg)), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                sqlite3_free(zErrMsg);
            }
            Console::WriteLine("Таблица создана (или уже существовала).");

            LoadProducts(); // Загружаем данные при запуске формы
        }

    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }

        virtual void OnClosed(EventArgs^ e) override {
            // Закрываем соединение с базой данных при закрытии формы
            if (db != nullptr) {
                sqlite3_close(db);
                Console::WriteLine("Соединение с базой данных закрыто.");
            }
            __super::OnClosed(e);
        }

    private: System::Windows::Forms::DataGridView^ dataGridViewProducts;
    private: System::Windows::Forms::Button^ btnAddProduct;
    private: System::Windows::Forms::TextBox^ textBoxName;
    private: System::Windows::Forms::TextBox^ textBoxDescription;
    private: System::Windows::Forms::TextBox^ textBoxPrice;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->dataGridViewProducts = (gcnew System::Windows::Forms::DataGridView());
            this->btnAddProduct = (gcnew System::Windows::Forms::Button());
            this->textBoxName = (gcnew System::Windows::Forms::TextBox());
            this->textBoxDescription = (gcnew System::Windows::Forms::TextBox());
            this->textBoxPrice = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProducts))->BeginInit();
            this->SuspendLayout();
            //
            // dataGridViewProducts
            //
            this->dataGridViewProducts->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridViewProducts->Location = System::Drawing::Point(12, 12);
            this->dataGridViewProducts->Name = L"dataGridViewProducts";
            this->dataGridViewProducts->Size = System::Drawing::Size(560, 200);
            this->dataGridViewProducts->TabIndex = 0;
            //
            // btnAddProduct
            //
            this->btnAddProduct->Location = System::Drawing::Point(245, 265);
            this->btnAddProduct->Name = L"btnAddProduct";
            this->btnAddProduct->Size = System::Drawing::Size(75, 23);
            this->btnAddProduct->TabIndex = 1;
            this->btnAddProduct->Text = L"Добавить";
            this->btnAddProduct->UseVisualStyleBackColor = true;
            this->btnAddProduct->Click += gcnew System::EventHandler(this, &Form1::btnAddProduct_Click);
            //
            // textBoxName
            //
            this->textBoxName->Location = System::Drawing::Point(97, 239);
            this->textBoxName->Name = L"textBoxName";
            this->textBoxName->Size = System::Drawing::Size(100, 20);
            this->textBoxName->TabIndex = 2;
            //
            // textBoxDescription
            //
            this->textBoxDescription->Location = System::Drawing::Point(97, 265);
            this->textBoxDescription->Name = L"textBoxDescription";
            this->textBoxDescription->Size = System::Drawing::Size(100, 20);
            this->textBoxDescription->TabIndex = 3;
            //
            // textBoxPrice
            //
            this->textBoxPrice->Location = System::Drawing::Point(97, 291);
            this->textBoxPrice->Name = L"textBoxPrice";
            this->textBoxPrice->Size = System::Drawing::Size(100, 20);
            this->textBoxPrice->TabIndex = 4;
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(12, 242);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(38, 13);
            this->label1->TabIndex = 5;
            this->label1->Text = L"Name:";
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(12, 268);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(63, 13);
            this->label2->TabIndex = 6;
            this->label2->Text = L"Description:";
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(12, 294);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(34, 13);
            this->label3->TabIndex = 7;
            this->label3->Text = L"Price:";
            //
            // Form1
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(584, 321);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->textBoxPrice);
            this->Controls->Add(this->textBoxDescription);
            this->Controls->Add(this->textBoxName);
            this->Controls->Add(this->btnAddProduct);
            this->Controls->Add(this->dataGridViewProducts);
            this->Name = L"Form1";
            this->Text = L"Пример работы с SQLite";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProducts))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        sqlite3* db = nullptr;
        char* zErrMsg = nullptr;
        sqlite3_stmt* stmt = nullptr;

    private: System::Void LoadProducts() {
        // Загрузка данных из таблицы Products и отображение в DataGridView
        if (db == nullptr) {
            MessageBox::Show("База данных не открыта.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        dataGridViewProducts->Rows->Clear();
        dataGridViewProducts->Columns->Clear();

        const char* sqlSelect = "SELECT id, name, description, price FROM Products;";
        int rc = sqlite3_prepare_v2(db, sqlSelect, -1, &stmt, nullptr);

        if (rc != SQLITE_OK) {
            MessageBox::Show(String::Format("Ошибка подготовки запроса: {0}", gcnew String(sqlite3_errmsg(db))), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Создание столбцов DataGridView
        dataGridViewProducts->Columns->Add("id", "ID");
        dataGridViewProducts->Columns->Add("name", "Name");
        dataGridViewProducts->Columns->Add("description", "Description");
        dataGridViewProducts->Columns->Add("price", "Price");

        // Заполнение DataGridView данными из базы
        while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            String^ name = gcnew String((const char*)sqlite3_column_text(stmt, 1));
            String^ description = gcnew String((const char*)sqlite3_column_text(stmt, 2));
            double price = sqlite3_column_double(stmt, 3);

            dataGridViewProducts->Rows->Add(id, name, description, price);
        }

        if (rc != SQLITE_DONE) {
            MessageBox::Show(String::Format("Ошибка выполнения запроса: {0}", gcnew String(sqlite3_errmsg(db))), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

        sqlite3_finalize(stmt); // Освобождаем ресурсы
    }

    private: System::Void btnAddProduct_Click(System::Object^ sender, System::EventArgs^ e) {
        // Добавление нового продукта в базу данных
        if (db == nullptr) {
            MessageBox::Show("База данных не открыта.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Получаем данные из текстовых полей
        String^ name = textBoxName->Text;
        String^ description = textBoxDescription->Text;
        double price = 0.0;
        try {
            price = System::Convert::ToDouble(textBoxPrice->Text);
        }
        catch (Exception^ ex) {
            MessageBox::Show("Неверный формат цены.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return; // Прекращаем выполнение, если цена неверна
        }

        // SQL-запрос для вставки данных
        const char* sqlInsert = "INSERT INTO Products (name, description, price) VALUES (?, ?, ?);";
        int rc = sqlite3_prepare_v2(db, sqlInsert, -1, &stmt, nullptr);

        if (rc != SQLITE_OK) {
            MessageBox::Show(String::Format("Ошибка подготовки запроса: {0}", gcnew String(sqlite3_errmsg(db))), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Привязываем параметры
        sqlite3_bind_text(stmt, 1, (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(name)).ToPointer(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(description)).ToPointer(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_double(stmt, 3, price);

        // Выполняем запрос
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            MessageBox::Show(String::Format("Ошибка выполнения запроса: {0}", gcnew String(sqlite3_errmsg(db))), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        else {
            Console::WriteLine("Продукт успешно добавлен.");
            LoadProducts(); // Обновляем DataGridView
        }

        // Освобождаем ресурсы
        sqlite3_finalize(stmt);
        System::Runtime::InteropServices::Marshal::FreeHGlobal(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(name));
        System::Runtime::InteropServices::Marshal::FreeHGlobal(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(description));

        // Очищаем текстовые поля
        textBoxName->Clear();
        textBoxDescription->Clear();
        textBoxPrice->Clear();
    }
    };
}