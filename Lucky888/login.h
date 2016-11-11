#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "main.h"
using namespace std;

#pragma once

namespace Lucky888 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  accountlabel;
	protected: 
	private: System::Windows::Forms::Label^  passwordlabel;
	private: System::Windows::Forms::TextBox^  actextBox;
	private: System::Windows::Forms::TextBox^  pwtextBox;
	private: System::Windows::Forms::Button^  loginbutton;


	private: System::Windows::Forms::Button^  newgamebutton;

	protected: 


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->accountlabel = (gcnew System::Windows::Forms::Label());
			this->passwordlabel = (gcnew System::Windows::Forms::Label());
			this->actextBox = (gcnew System::Windows::Forms::TextBox());
			this->pwtextBox = (gcnew System::Windows::Forms::TextBox());
			this->loginbutton = (gcnew System::Windows::Forms::Button());
			this->newgamebutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// accountlabel
			// 
			this->accountlabel->AutoSize = true;
			this->accountlabel->Location = System::Drawing::Point(24, 50);
			this->accountlabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->accountlabel->Name = L"accountlabel";
			this->accountlabel->Size = System::Drawing::Size(50, 13);
			this->accountlabel->TabIndex = 0;
			this->accountlabel->Text = L"Account:";
			// 
			// passwordlabel
			// 
			this->passwordlabel->AutoSize = true;
			this->passwordlabel->Location = System::Drawing::Point(16, 86);
			this->passwordlabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->passwordlabel->Name = L"passwordlabel";
			this->passwordlabel->Size = System::Drawing::Size(56, 13);
			this->passwordlabel->TabIndex = 1;
			this->passwordlabel->Text = L"Password:";
			// 
			// actextBox
			// 
			this->actextBox->Location = System::Drawing::Point(76, 48);
			this->actextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->actextBox->Name = L"actextBox";
			this->actextBox->Size = System::Drawing::Size(120, 20);
			this->actextBox->TabIndex = 2;
			// 
			// pwtextBox
			// 
			this->pwtextBox->Location = System::Drawing::Point(76, 86);
			this->pwtextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pwtextBox->Name = L"pwtextBox";
			this->pwtextBox->PasswordChar = '*';
			this->pwtextBox->Size = System::Drawing::Size(120, 20);
			this->pwtextBox->TabIndex = 3;
			// 
			// loginbutton
			// 
			this->loginbutton->Location = System::Drawing::Point(76, 124);
			this->loginbutton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->loginbutton->Name = L"loginbutton";
			this->loginbutton->Size = System::Drawing::Size(57, 37);
			this->loginbutton->TabIndex = 4;
			this->loginbutton->Text = L"Login";
			this->loginbutton->UseVisualStyleBackColor = true;
			this->loginbutton->Click += gcnew System::EventHandler(this, &Login::loginbutton_Click);
			// 
			// newgamebutton
			// 
			this->newgamebutton->Location = System::Drawing::Point(137, 124);
			this->newgamebutton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->newgamebutton->Name = L"newgamebutton";
			this->newgamebutton->Size = System::Drawing::Size(57, 37);
			this->newgamebutton->TabIndex = 7;
			this->newgamebutton->Text = L"New game";
			this->newgamebutton->UseVisualStyleBackColor = true;
			this->newgamebutton->Click += gcnew System::EventHandler(this, &Login::newgamebutton_Click);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(212, 207);
			this->Controls->Add(this->newgamebutton);
			this->Controls->Add(this->loginbutton);
			this->Controls->Add(this->pwtextBox);
			this->Controls->Add(this->actextBox);
			this->Controls->Add(this->passwordlabel);
			this->Controls->Add(this->accountlabel);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Login";
			this->Text = L"Game Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void loginbutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 String^ acinput;
				 String^ pwinput;
				 acinput = actextBox->Text;
				 pwinput = pwtextBox->Text;
				 //Get input from the user

				 char* systemacinput = (char*)Marshal::StringToHGlobalAnsi(acinput).ToPointer();


				 string file(systemacinput);
				 file += ".txt";

				 ifstream fin;
				 fin.open(file);
				 if(fin.is_open())
				 {
					 string ac;
					 string pw;
					 int credits;
					 fin >> ac;
					 fin >> pw;
					 fin >> credits;
					 String^ acstr = gcnew String(ac.c_str());
					 String^ pwstr = gcnew String(pw.c_str());
					 //Get ac,pw from data and convert to managed String^

					 if(acinput==acstr && pwinput==pwstr)
					 {
						 MessageBox::Show(acinput + " ,wellcome back to Lucky888!","Login successfully",MessageBoxButtons::OK);
						 Main^ mainpage = gcnew Main(acinput,credits,pwinput);
						 this->Hide();
						 mainpage->ShowDialog();
					 }
					 else
					 {
						 MessageBox::Show("Wrong password! please try again","Login unsuccessfully",MessageBoxButtons::OK);
					 }
					 //Checking the ac and pw
				 }
				 else
				 {
					 MessageBox::Show("You have no record before!","Player not exist",MessageBoxButtons::OK);
				 }
				 

				 
			 }
	private: System::Void newgamebutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 MessageBox::Show("Wellcome to Lucky888!","New player",MessageBoxButtons::OK);
				 Main^ mainpage = gcnew Main("New player",100,"123456");
				 this->Hide();
				 mainpage->ShowDialog();			 
			 }
};
}

