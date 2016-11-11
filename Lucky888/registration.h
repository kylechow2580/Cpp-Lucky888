#include <iostream>
#include <fstream>
#include <string>
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
	/// Summary for registration
	/// </summary>
	public ref class registration : public System::Windows::Forms::Form
	{
	public:
		String^ getAcName()
		{
			return temp;
		}
		registration(int c)
		{
			credits = c;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~registration()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  aclabel;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  regbutton;
	private: System::Windows::Forms::TextBox^  actextBox;
	private: System::Windows::Forms::TextBox^  pwtextBox;

	private:
		/// <summary>
		/// Required designer variable.
		String^ temp;
		int credits;
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->aclabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->regbutton = (gcnew System::Windows::Forms::Button());
			this->actextBox = (gcnew System::Windows::Forms::TextBox());
			this->pwtextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// aclabel
			// 
			this->aclabel->AutoSize = true;
			this->aclabel->Location = System::Drawing::Point(22, 62);
			this->aclabel->Name = L"aclabel";
			this->aclabel->Size = System::Drawing::Size(50, 13);
			this->aclabel->TabIndex = 0;
			this->aclabel->Text = L"Account:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 99);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Password:";
			// 
			// regbutton
			// 
			this->regbutton->Location = System::Drawing::Point(60, 136);
			this->regbutton->Name = L"regbutton";
			this->regbutton->Size = System::Drawing::Size(75, 23);
			this->regbutton->TabIndex = 2;
			this->regbutton->Text = L"Register";
			this->regbutton->UseVisualStyleBackColor = true;
			this->regbutton->Click += gcnew System::EventHandler(this, &registration::regbutton_Click);
			// 
			// actextBox
			// 
			this->actextBox->Location = System::Drawing::Point(77, 59);
			this->actextBox->Name = L"actextBox";
			this->actextBox->Size = System::Drawing::Size(100, 20);
			this->actextBox->TabIndex = 3;
			// 
			// pwtextBox
			// 
			this->pwtextBox->Location = System::Drawing::Point(77, 96);
			this->pwtextBox->Name = L"pwtextBox";
			this->pwtextBox->PasswordChar = '*';
			this->pwtextBox->Size = System::Drawing::Size(100, 20);
			this->pwtextBox->TabIndex = 4;
			// 
			// registration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(197, 188);
			this->Controls->Add(this->pwtextBox);
			this->Controls->Add(this->actextBox);
			this->Controls->Add(this->regbutton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->aclabel);
			this->Name = L"registration";
			this->Text = L"Registration";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void regbutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 ofstream fout;
				 String^ acinput = actextBox->Text;
				 String^ pwinput = pwtextBox->Text;

				 temp = acinput;

				 char* ac = (char*)Marshal::StringToHGlobalAnsi(acinput).ToPointer();
				 char* pw = (char*)Marshal::StringToHGlobalAnsi(pwinput).ToPointer();
				 

				 string acstr(ac);
				 string pwstr(pw);

				 fout.open(acstr + ".txt");
				 fout << acstr << endl;
				 fout << pwstr << endl;
				 fout << credits;
				 fout.close();

				 Marshal::FreeHGlobal((IntPtr)ac);
				 Marshal::FreeHGlobal((IntPtr)pw);



				 this->Close();
			 }
};
}
