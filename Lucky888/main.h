#include "pokercard.h"
#include "registration.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
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
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{

	public:
		///<Rule checking function>
		bool onePairsCheck(int* fiveCardValue)
		{
			//Combination = 4C4
			bool case1 = false; // e.g 1,1,4,5,6
			bool case2 = false; // e.g 1,2,2,3,4
			bool case3 = false; // e.g 1,3,5,5,7
			bool case4 = false; // e.g 1,2,3,4,4			

			if(fiveCardValue[0] == fiveCardValue[1] && fiveCardValue[1] != fiveCardValue[2] && fiveCardValue[2] != fiveCardValue[3] && fiveCardValue[3] != fiveCardValue[4])
			{
				case1 = true;
			}
			if(fiveCardValue[0] != fiveCardValue[1] && fiveCardValue[1] == fiveCardValue[2] && fiveCardValue[2] != fiveCardValue[3] && fiveCardValue[3] != fiveCardValue[4])
			{
				case2 = true;
			}
			if(fiveCardValue[0] != fiveCardValue[1] && fiveCardValue[1] != fiveCardValue[2] && fiveCardValue[2] == fiveCardValue[3] && fiveCardValue[3] != fiveCardValue[4])
			{
				case3 = true;
			}
			if(fiveCardValue[0] != fiveCardValue[1] && fiveCardValue[1] != fiveCardValue[2] && fiveCardValue[2] != fiveCardValue[3] && fiveCardValue[3] == fiveCardValue[4])
			{
				case4 = true;
			}			
			return (case1||case2||case3||case4);
		}
		bool twoPairsCheck(int* fiveCardValue)
		{
			bool case1 = false; //e.g 1,1,2,2,3 
			bool case2 = false; //e.g 1,1,3,5,5
			bool case3 = false; //e.g 1,2,2,3,3

			if(fiveCardValue[0] == fiveCardValue[1] && fiveCardValue[1] != fiveCardValue[2] && fiveCardValue[2] == fiveCardValue[3] && fiveCardValue[3] != fiveCardValue[4] && fiveCardValue[0] != fiveCardValue[4])
			{
				case1 = true;
			}
			if(fiveCardValue[0] == fiveCardValue[1] && fiveCardValue[1] != fiveCardValue[2] && fiveCardValue[2] != fiveCardValue[3] && fiveCardValue[3] == fiveCardValue[4])
			{
				case2 = true;
			}
			if(fiveCardValue[0] != fiveCardValue[1] && fiveCardValue[1] == fiveCardValue[2] && fiveCardValue[2] != fiveCardValue[3] && fiveCardValue[3] == fiveCardValue[4] && fiveCardValue[0] != fiveCardValue[4])
			{
				case3 = true;
			}						
			return (case1||case2||case3);
		}
		bool threeOfaKindCheck(int* fiveCardValue)
		{
			bool case1 = false; // e.g 1,2,4,4,4,
			bool case2 = false; // e.g 2,6,6,6,9
			bool case3 = false; // e.g 6,6,6,10,11

			if(fiveCardValue[0] != fiveCardValue[1] && fiveCardValue[2] == fiveCardValue[3] && fiveCardValue[3] == fiveCardValue[4])
			{
				case1 = true;
			}
			if(fiveCardValue[0] < fiveCardValue[1] && fiveCardValue[1] == fiveCardValue[2] && fiveCardValue[2] == fiveCardValue[3] && fiveCardValue[3] < fiveCardValue[4])
			{
				case2 = true;
			}
			if(fiveCardValue[0] == fiveCardValue[1] && fiveCardValue[1] == fiveCardValue[2] && fiveCardValue[3] != fiveCardValue[4])
			{
				case3 = true;
			}
			return (case1||case2||case3);
		}
		bool fullHouseCheck(int* fiveCardValue)
		{
			bool case1 = false; //3,3,3,7,7
			bool case2 = false; //7,7,11,11,11
			
			if(fiveCardValue[0] == fiveCardValue[1] && fiveCardValue[1] == fiveCardValue[2] && fiveCardValue[3] == fiveCardValue[4])
			{
				case1 = true;
			}
			if(fiveCardValue[0] == fiveCardValue[1] && fiveCardValue[2] == fiveCardValue[3] && fiveCardValue[3] == fiveCardValue[4])
			{
				case2 = true;
			}
			return (case1||case2);
		}
		bool fourOfaKindCheck(int* fiveCardValue)
		{
			bool case1 = false; // 4,4,4,4,7
			bool case2 = false; // 3,6,6,6,6

			if(fiveCardValue[0] == fiveCardValue[1] && fiveCardValue[1] == fiveCardValue[2] && fiveCardValue[2] == fiveCardValue[3])
			{
				case1 = true;
			}
			if(fiveCardValue[1] == fiveCardValue[2] && fiveCardValue[2] == fiveCardValue[3] && fiveCardValue[3] == fiveCardValue[4])
			{
				case2 = true;
			}
			return (case1||case2);
		}
		bool straightFlushCheck(int* fiveCardValue,string* fiveCardType)
		{
			if(flushCheck(fiveCardType) && straightCheck(fiveCardValue))
			{				
				return true;
			}
			else
			{
				return false;
			}
		}
		bool royalFlushCheck(int* fiveCardValue,string* fiveCardType)
		{
			if(fiveCardValue[0]==1 && fiveCardValue[1]==10 && fiveCardValue[2]==11 && fiveCardValue[3]==12 && fiveCardValue[4]==13)
			{
				if(flushCheck(fiveCardType) == true)
				{
					return true;
				}
			}
				else
				{
					return false;
				}
		}
		bool flushCheck(string* fiveCardType)
		{
			for(int i=0;i<4;i++)
			{
				if(fiveCardType[i] != fiveCardType[i+1])
				{
						return false;
				}
			}
			return true;
		}
		bool straightCheck(int* fiveCardValue)
		{
			if(fiveCardValue[0]+1 == fiveCardValue[1] && fiveCardValue[1]+1 == fiveCardValue[2] && fiveCardValue[2]+1 == fiveCardValue[3] && fiveCardValue[3]+1 == fiveCardValue[4])
			{
				return true;
			}
			else if(fiveCardValue[0]==1 && fiveCardValue[1]==2 && fiveCardValue[2]==3 && fiveCardValue[3]==4 && fiveCardValue[4]==13)
			{
				return true;
			}
			else if(fiveCardValue[0]==1 && fiveCardValue[1]==2 && fiveCardValue[2]==3 && fiveCardValue[3]==12 && fiveCardValue[4]==13)
			{
				return true;
			}
			else if(fiveCardValue[0]==1 && fiveCardValue[1]==2 && fiveCardValue[2]==11 && fiveCardValue[3]==12 && fiveCardValue[4]==13)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		void checkResult()
		{
			// Proportional
			// y = won_credits * x
			// x = pay/20		


			bool straight = false;
			bool flush = false;
			bool royalFlush = false;
			bool straightFlush = false;
			bool fourOfaKind = false;
			bool fullHouse = false;
			bool threeOfaKind = false;
			bool twoPairs = false;
			bool onePairs = false;
			//Result checking



			int value[6];
			string type[6];
			for(int i=0;i<6;i++)
			{
				value[i] = drawn[i].getValue();
				type[i] = drawn[i].getType();
			}
			//Collect the data need from pokercard object


			int fiveCardValue[5];
			string fiveCardType[5];
			//Because in the final term we got 6 cards
			//But the combination is depends on 5 cards
			//Devide into 5 cards


			for(int i=5;i>=0;i--)
			{
				int max = 0;
				int index;
				int temp;
				string strtemp;
				for(int j=i;j>=0;j--)
				{
					if(value[j]>max)
					{
						max = value[j];
						index = j;
					}
				}
				temp = value[i];
				strtemp = type[i];
				value[i] = value[index];
				type[i] = type[index];
				value[index] = temp;
				type[index] = strtemp;
			}
			//A selection sort to sort the data in order
			//From wiki algorithm
			



			for(int i=0;i<6;i++)
			{
				bool meet = false;
				for(int j=0;j<5;j++)
				{
					if(i==j)
					{
						meet = true;
						fiveCardValue[j] = value[j+1];
						fiveCardType[j] = type[j+1];
					}
					else if(meet)
					{
						fiveCardValue[j] = value[j+1];
						fiveCardType[j] = type[j+1];
					}
					else
					{
						fiveCardValue[j] = value[j];
						fiveCardType[j] = type[j];
					}					
				}
				//5 cards out of 6 check. different combination

				if(royalFlush == false)
				{
					royalFlush = royalFlushCheck(fiveCardValue,fiveCardType);					
				}

				if(straightFlush == false)
				{
					straightFlush = straightFlushCheck(fiveCardValue,fiveCardType);					
				}

				if(straight == false)
				{
					straight = straightCheck(fiveCardValue);					
				}

				if(flush == false)
				{
					flush = flushCheck(fiveCardType);					
				}

				if(fourOfaKind == false)
				{
					fourOfaKind = fourOfaKindCheck(fiveCardValue);
				}

				if(fullHouse == false)
				{
					fullHouse = fullHouseCheck(fiveCardValue);
				}	

				if(threeOfaKind == false)
				{
					threeOfaKind = threeOfaKindCheck(fiveCardValue);
				}

				if(twoPairs == false)
				{
					twoPairs = twoPairsCheck(fiveCardValue);
				}

				if(onePairs == false)
				{
					onePairs = onePairsCheck(fiveCardValue);
				}
			}


			//Decide which result satisfied
			if(royalFlush == true)
			{
				MessageBox::Show("This is a royal","Royal",MessageBoxButtons::OK);
				win = true;
				gain = 10000 * pay/20;
				//writeCredits(10000 * pay/20);
			}
			else if(straightFlush == true)
			{
				MessageBox::Show("This is a straightFlush","StraightFlush",MessageBoxButtons::OK);
				win = true;
				gain = 4000 * pay/20;
				//writeCredits(4000 * pay/20);
			}
			else if(fourOfaKind == true)
			{
				MessageBox::Show("This is four of a kind","Four of a kind",MessageBoxButtons::OK);
				win = true;
				gain = 800 * pay/20;
				//writeCredits(800 * pay/20);
			}
			else if(fullHouse == true)
			{
				MessageBox::Show("This is full house","Full house",MessageBoxButtons::OK);
				win = true;
				gain = 200 * pay/20;
				//writeCredits(200 * pay/20);
			}	
			else if(flush == true)
			{
				MessageBox::Show("This is a flush","Flush",MessageBoxButtons::OK);
				win = true;
				gain = 150 * pay/20;
				//writeCredits(150 * pay/20);
			}
			else if(straight == true)
			{
				MessageBox::Show("This is a straight","Straight",MessageBoxButtons::OK);
				win = true;
				gain = 100 * pay/20;
				//writeCredits(100 * pay/20);
			}
					
			else if(threeOfaKind == true)
			{
				MessageBox::Show("This is three of a kind","Three of a kind",MessageBoxButtons::OK);
				win = true;
				gain = 60 * pay/20;
				//writeCredits(60 * pay/20);
			}
			else if(twoPairs == true)
			{
				MessageBox::Show("This is two pairs","Two pairs",MessageBoxButtons::OK);
				win = true;
				gain = 40 * pay/20;
				//writeCredits(40 * pay/20);
			}
			else if(onePairs == true)
			{
				MessageBox::Show("This is one pairs","One pairs",MessageBoxButtons::OK);
				win = true;
				gain = 20 * pay/20;
				//writeCredits(20 * pay/20);
			}
			else
			{
				MessageBox::Show("Nothing","Sorry",MessageBoxButtons::OK);
				win = false;
				gain = 0;
			}
		}
		///</Rule checking function>
		///<Game flow control function>
		PokerCard giveCard(int type, int value)//give the card to the player with exact card
		{
			//For debugging
			check[type][value-1] = true;
			return card[type][value-1];
		}
		PokerCard giveCard()//give the card to the player randomly
		{
			int type;
			int value;
			do
			{
				type = rand() % 4;
				value = rand() % 14;
			}while(check[type][value]==true);
			check[type][value] = true;

			if(type==0 || type==2)
			{
				check[0][value] = true;
				check[2][value] = true;
			}

			if(type==1 || type==3)
			{
				check[1][value] = true;
				check[3][value] = true;
			}
			//Because only 2 joker, so if we get diamand14,then heart14 also be counted as exist already.
			return card[type][value];
		}	
		void checkJoker()//Check joker whether exist
		{
			for(int i=0;i<6;i++)
			{
				if(drawn[i].getValue() == 14)
				{
					comboarr[i]->Enabled = true;
					numberarr[i]->Enabled = true;
					buttonarr[i]->Enabled = true;
				}
			}
		}
		void writeCredits(int num) //Count and write the credits to the windows form
		{
			credits += num;
			creditsstr = "" + credits;
			this->Creditsvaluelabel->Text = creditsstr;
		}
		void countTurn() //Count the result and check remaining money is enough or not
		{		
			checkResult();
		}
		void startGame() // Set all the enviornment to start game
		{			

			if(credits<20)
			{
				this->playbutton->Enabled = false;
				MessageBox::Show("You have no enough credits!","Credits",MessageBoxButtons::OK);

			}
			else
			{
				this->playbutton->Enabled = true;
			}			
			this->swapbutton->Enabled = false;
			this->extrabutton->Enabled = false;
			this->finalbutton->Enabled = false;
			this->newturnbutton->Enabled = false;
			this->xbutton->Enabled = false;
			this->bigbutton->Enabled = false;
			this->smallbutton->Enabled = false;
			this->pictureBox8->Image = nullptr;

			for(int i=0;i<6;i++)
			{
				comboarr[i]->SelectedIndex = 0;
				numberarr[i]->SelectedIndex = 0;
				comboarr[i]->Enabled = false;
				numberarr[i]->Enabled = false;
				buttonarr[i]->Enabled = false;
				picBox[i]->Location = System::Drawing::Point(650, 29);
				if(i<5)
				{
					picBox[i]->ImageLocation = "images/hero.jpg";
				}
			}
			picBox[5]->Image = nullptr; 
			check_initialization();
			swap = false;
			extra = false;			
		}
		void changeCard(int n)
		{
			bool exist = false;
			char* numberptr = (char*)Marshal::StringToHGlobalAnsi(numberarr[n]->Text).ToPointer();
			char* comboptr = (char*)Marshal::StringToHGlobalAnsi(comboarr[n]->Text).ToPointer();

			int number = atoi(numberptr);
			string type(comboptr);


			Marshal::FreeHGlobal((IntPtr)numberptr);
			Marshal::FreeHGlobal((IntPtr)comboptr);

			for(int i=0;i<6;i++)
			{
				if(drawn[i].getType() == type && drawn[i].getValue() == number)
				{
					MessageBox::Show("This is already exists","Wrong",MessageBoxButtons::OK);
					exist = true;
				}
			}			

			if(exist != true)
			{
				check[typeNumber(type)][number] = true;			
				buttonarr[n]->Enabled = false;
				comboarr[n]->Enabled = false;
				numberarr[n]->Enabled = false;

				drawn[n].setType(type);
				drawn[n].setValue(number);

				this->picBox[n]->ImageLocation = "images/" + gcnew String(type.c_str()) + number + ".jpg";
			}
				
			
		}
		void check_initialization()//initialization of the check list
		{
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<14;j++)
				{
					check[i][j] = false;
				}
			}
		}
		int typeNumber(string s)//change the card type in string type to number
		{
			if(s == "spades")
			{
				return 0;
			}
			else if(s == "heart")
			{
				return 1;
			}
			else if(s == "clubs")
			{
				return 2;
			}
			else if(s == "diamand")
			{
				return 3;
			}
		}
		///</Game flow control function>
		Main(String^ ac,int credits, String^pw)
		{
			acstr = ac;
			pwstr = pw;
			debug = false;
			//Data setting
			srand((unsigned int)time(NULL));
			//According to the computer time get some random num,avoid every time the result will be the same


			InitializeComponent();
			this->paytextBox->Text = "20";
			this->acvaluelabel->Text = acstr;
			this->credits = credits;
			writeCredits(0);
			//Set user record

			
			this->swapbutton->Enabled = false;
			this->extrabutton->Enabled = false;
			this->newturnbutton->Enabled = false;
			this->cheatbutton ->Enabled = false;
			


			//System UI and data setting
			picBox = gcnew array<System::Windows::Forms::PictureBox^>(6);
			picBox[0] = this->pictureBox1;
			picBox[1] = this->pictureBox2;
			picBox[2] = this->pictureBox3;
			picBox[3] = this->pictureBox4;
			picBox[4] = this->pictureBox5;
			picBox[5] = this->pictureBox6;
						


			comboarr = gcnew array<System::Windows::Forms::ComboBox^>(6);
			comboarr[0] = this->comboBox1;
			comboarr[1] = this->comboBox2;
			comboarr[2] = this->comboBox3;
			comboarr[3] = this->comboBox4;
			comboarr[4] = this->comboBox5;
			comboarr[5] = this->comboBox6;


			numberarr = gcnew array<System::Windows::Forms::ComboBox^>(6);
			numberarr[0] = this->number1;
			numberarr[1] = this->number2;
			numberarr[2] = this->number3;
			numberarr[3] = this->number4;
			numberarr[4] = this->number5;
			numberarr[5] = this->number6;


			buttonarr = gcnew array<System::Windows::Forms::Button^>(6);
			buttonarr[0] = this->button1;
			buttonarr[1] = this->button2;
			buttonarr[2] = this->button3;
			buttonarr[3] = this->button4;
			buttonarr[4] = this->button5;
			buttonarr[5] = this->button6;


			for(int i=0;i<6;i++)
			{
				comboarr[i]->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"spades", L"heart", L"clubs",L"diamand"});
				numberarr[i]->Items->AddRange(gcnew cli::array< System::Object^  >(13) {L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", 
				L"10", L"11", L"12", L"13"});
			}
			//System UI and data setting
			



			card = new PokerCard*[4];
			for(int i=0;i<4;i++)
			{
				card[i] = new PokerCard[14];
			}
			// Declare dynamic 2d array about card



			for(int i=0;i<4;i++)
			{
				if(i==0)
				{
					for(int j=0;j<14;j++)
					{
						card[i][j].setType("spades");
						card[i][j].setValue(j+1);
					}
				}
				else if(i==1)
				{
					for(int j=0;j<14;j++)
					{
						card[i][j].setType("heart");
						card[i][j].setValue(j+1);
					}
				}
				else if(i==2)
				{
					for(int j=0;j<14;j++)
					{
						card[i][j].setType("clubs");
						card[i][j].setValue(j+1);
					}
				}
				else
				{
					for(int j=0;j<14;j++)
					{
						card[i][j].setType("diamand");
						card[i][j].setValue(j+1);
					}
				}
			}
			//Set all the data about poker card

			
			drawn = new PokerCard[6];
			check = new bool*[4];
			for(int i=0;i<4;i++)
			{
				check[i] = new bool[14];
			}			
			//Declare a check list to check whether the card are already exist				


			startGame();
			this->swapbutton->Enabled = false;
			this->extrabutton->Enabled = false;
			this->newturnbutton->Enabled = false;
			//Environment setting for the first round.
		}
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
				for(int i=0;i<4;i++)
				{
					delete card[i];
					delete check[i];
				}
				delete card;
				delete check;
				delete drawn;
				delete guess;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		PokerCard** card;
		PokerCard* drawn;
		PokerCard* guess;
		String^ creditsstr;
		String^ acstr;
		String^ pwstr;
		bool** check;		
		bool swap;
		bool extra;
		bool debug;
		bool correct;
		bool win;
		int gain;
		int credits;
		int pay;
		int second;

		 /// </summary>
	
	protected: 
		array<System::Windows::Forms::PictureBox^>^ picBox;
		array<System::Windows::Forms::ComboBox^>^ comboarr;
		array<System::Windows::Forms::ComboBox^>^ numberarr;
		array<System::Windows::Forms::Button^>^ buttonarr;
		private: System::Windows::Forms::Label^  aclabel;
		private: System::Windows::Forms::Label^  creditslabel;
		private: System::Windows::Forms::Label^  acvaluelabel;
		private: System::Windows::Forms::Label^  Creditsvaluelabel;
		private: System::Windows::Forms::PictureBox^  pictureBox1;
		private: System::Windows::Forms::PictureBox^  pictureBox2;
		private: System::Windows::Forms::PictureBox^  pictureBox3;
		private: System::Windows::Forms::PictureBox^  pictureBox6;
		private: System::Windows::Forms::PictureBox^  pictureBox5;
		private: System::Windows::Forms::PictureBox^  pictureBox4;
		private: System::Windows::Forms::Button^  swapbutton;
		private: System::Windows::Forms::Button^  newturnbutton;
		private: System::Windows::Forms::Button^  extrabutton;
		private: System::Windows::Forms::Button^  playbutton;
		private: System::Windows::Forms::Button^  exitbutton;
		private: System::Windows::Forms::PictureBox^  pictureBox7;
		private: System::Windows::Forms::TextBox^  paytextBox;
		private: System::Windows::Forms::Label^  paylabel;
		private: System::Windows::Forms::Timer^  timer1;
		private: System::Windows::Forms::Timer^  timer2;
		private: System::Windows::Forms::Timer^  timer3;
		private: System::Windows::Forms::Timer^  timer4;
		private: System::Windows::Forms::Timer^  timer5;
		private: System::Windows::Forms::Timer^  timer6;
		private: System::Windows::Forms::Button^  finalbutton;
		private: System::Windows::Forms::Button^  savebutton;
		private: System::Windows::Forms::ComboBox^  comboBox1;
		private: System::Windows::Forms::ComboBox^  comboBox2;
		private: System::Windows::Forms::ComboBox^  comboBox3;
		private: System::Windows::Forms::ComboBox^  comboBox4;
		private: System::Windows::Forms::ComboBox^  comboBox5;
		private: System::Windows::Forms::ComboBox^  comboBox6;
		private: System::Windows::Forms::ComboBox^  number6;
		private: System::Windows::Forms::ComboBox^  number5;
		private: System::Windows::Forms::ComboBox^  number4;
		private: System::Windows::Forms::ComboBox^  number3;
		private: System::Windows::Forms::ComboBox^  number2;
		private: System::Windows::Forms::ComboBox^  number1;
		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Button^  button3;
		private: System::Windows::Forms::Button^  button4;
		private: System::Windows::Forms::Button^  button5;
		private: System::Windows::Forms::Button^  button6;
		private: System::Windows::Forms::Button^  cheatbutton;
		private: System::Windows::Forms::PictureBox^  pictureBox8;
		private: System::Windows::Forms::Button^  bigbutton;
		private: System::Windows::Forms::Button^  smallbutton;
		private: System::Windows::Forms::Button^  xbutton;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::Label^  label4;
		private: System::Windows::Forms::Label^  label5;
		private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent()
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->aclabel = (gcnew System::Windows::Forms::Label());
			this->creditslabel = (gcnew System::Windows::Forms::Label());
			this->acvaluelabel = (gcnew System::Windows::Forms::Label());
			this->Creditsvaluelabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->swapbutton = (gcnew System::Windows::Forms::Button());
			this->newturnbutton = (gcnew System::Windows::Forms::Button());
			this->extrabutton = (gcnew System::Windows::Forms::Button());
			this->playbutton = (gcnew System::Windows::Forms::Button());
			this->exitbutton = (gcnew System::Windows::Forms::Button());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->paytextBox = (gcnew System::Windows::Forms::TextBox());
			this->paylabel = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer5 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer6 = (gcnew System::Windows::Forms::Timer(this->components));
			this->finalbutton = (gcnew System::Windows::Forms::Button());
			this->savebutton = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->number6 = (gcnew System::Windows::Forms::ComboBox());
			this->number5 = (gcnew System::Windows::Forms::ComboBox());
			this->number4 = (gcnew System::Windows::Forms::ComboBox());
			this->number3 = (gcnew System::Windows::Forms::ComboBox());
			this->number2 = (gcnew System::Windows::Forms::ComboBox());
			this->number1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->cheatbutton = (gcnew System::Windows::Forms::Button());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->bigbutton = (gcnew System::Windows::Forms::Button());
			this->smallbutton = (gcnew System::Windows::Forms::Button());
			this->xbutton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->BeginInit();
			this->SuspendLayout();
			// 
			// aclabel
			// 
			this->aclabel->AutoSize = true;
			this->aclabel->BackColor = System::Drawing::Color::Transparent;
			this->aclabel->Location = System::Drawing::Point(525, 54);
			this->aclabel->Name = L"aclabel";
			this->aclabel->Size = System::Drawing::Size(50, 13);
			this->aclabel->TabIndex = 0;
			this->aclabel->Text = L"Account:";
			// 
			// creditslabel
			// 
			this->creditslabel->AutoSize = true;
			this->creditslabel->BackColor = System::Drawing::Color::Transparent;
			this->creditslabel->Location = System::Drawing::Point(533, 86);
			this->creditslabel->Name = L"creditslabel";
			this->creditslabel->Size = System::Drawing::Size(42, 13);
			this->creditslabel->TabIndex = 1;
			this->creditslabel->Text = L"Credits:";
			// 
			// acvaluelabel
			// 
			this->acvaluelabel->AutoSize = true;
			this->acvaluelabel->BackColor = System::Drawing::Color::Transparent;
			this->acvaluelabel->Location = System::Drawing::Point(581, 54);
			this->acvaluelabel->Name = L"acvaluelabel";
			this->acvaluelabel->Size = System::Drawing::Size(35, 13);
			this->acvaluelabel->TabIndex = 2;
			this->acvaluelabel->Text = L"label1";
			// 
			// Creditsvaluelabel
			// 
			this->Creditsvaluelabel->AutoSize = true;
			this->Creditsvaluelabel->BackColor = System::Drawing::Color::Transparent;
			this->Creditsvaluelabel->Location = System::Drawing::Point(581, 86);
			this->Creditsvaluelabel->Name = L"Creditsvaluelabel";
			this->Creditsvaluelabel->Size = System::Drawing::Size(35, 13);
			this->Creditsvaluelabel->TabIndex = 3;
			this->Creditsvaluelabel->Text = L"label2";
			// 
			// pictureBox1
			// 
			this->pictureBox1->ImageLocation = L"";
			this->pictureBox1->Location = System::Drawing::Point(75, 270);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(71, 96);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->ImageLocation = L"";
			this->pictureBox2->Location = System::Drawing::Point(189, 270);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(71, 96);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->ImageLocation = L"";
			this->pictureBox3->Location = System::Drawing::Point(302, 270);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(71, 96);
			this->pictureBox3->TabIndex = 6;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->ImageLocation = L"";
			this->pictureBox6->Location = System::Drawing::Point(650, 270);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(71, 96);
			this->pictureBox6->TabIndex = 9;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->ImageLocation = L"";
			this->pictureBox5->Location = System::Drawing::Point(534, 270);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(71, 96);
			this->pictureBox5->TabIndex = 8;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->ImageLocation = L"";
			this->pictureBox4->Location = System::Drawing::Point(416, 270);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(71, 96);
			this->pictureBox4->TabIndex = 7;
			this->pictureBox4->TabStop = false;
			// 
			// swapbutton
			// 
			this->swapbutton->BackColor = System::Drawing::Color::AliceBlue;
			this->swapbutton->Location = System::Drawing::Point(499, 572);
			this->swapbutton->Name = L"swapbutton";
			this->swapbutton->Size = System::Drawing::Size(75, 23);
			this->swapbutton->TabIndex = 10;
			this->swapbutton->Text = L"Swap";
			this->swapbutton->UseVisualStyleBackColor = false;
			this->swapbutton->Click += gcnew System::EventHandler(this, &Main::swapbutton_Click);
			// 
			// newturnbutton
			// 
			this->newturnbutton->BackColor = System::Drawing::Color::AliceBlue;
			this->newturnbutton->Location = System::Drawing::Point(50, 573);
			this->newturnbutton->Name = L"newturnbutton";
			this->newturnbutton->Size = System::Drawing::Size(133, 23);
			this->newturnbutton->TabIndex = 11;
			this->newturnbutton->Text = L"Start a new Turn";
			this->newturnbutton->UseVisualStyleBackColor = false;
			this->newturnbutton->Click += gcnew System::EventHandler(this, &Main::newturnbutton_Click);
			// 
			// extrabutton
			// 
			this->extrabutton->BackColor = System::Drawing::Color::AliceBlue;
			this->extrabutton->Location = System::Drawing::Point(621, 572);
			this->extrabutton->Name = L"extrabutton";
			this->extrabutton->Size = System::Drawing::Size(75, 23);
			this->extrabutton->TabIndex = 12;
			this->extrabutton->Text = L"Extra";
			this->extrabutton->UseVisualStyleBackColor = false;
			this->extrabutton->Click += gcnew System::EventHandler(this, &Main::extrabutton_Click);
			// 
			// playbutton
			// 
			this->playbutton->BackColor = System::Drawing::Color::AliceBlue;
			this->playbutton->Location = System::Drawing::Point(314, 573);
			this->playbutton->Name = L"playbutton";
			this->playbutton->Size = System::Drawing::Size(75, 23);
			this->playbutton->TabIndex = 13;
			this->playbutton->Text = L"Play";
			this->playbutton->UseVisualStyleBackColor = false;
			this->playbutton->Click += gcnew System::EventHandler(this, &Main::playbutton_Click);
			// 
			// exitbutton
			// 
			this->exitbutton->BackColor = System::Drawing::Color::AliceBlue;
			this->exitbutton->Location = System::Drawing::Point(-1, 649);
			this->exitbutton->Name = L"exitbutton";
			this->exitbutton->Size = System::Drawing::Size(75, 23);
			this->exitbutton->TabIndex = 14;
			this->exitbutton->Text = L"exit";
			this->exitbutton->UseVisualStyleBackColor = false;
			this->exitbutton->Click += gcnew System::EventHandler(this, &Main::exitbutton_Click);
			// 
			// pictureBox7
			// 
			this->pictureBox7->ImageLocation = L"images/back.jpg";
			this->pictureBox7->Location = System::Drawing::Point(650, 29);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(71, 96);
			this->pictureBox7->TabIndex = 15;
			this->pictureBox7->TabStop = false;
			// 
			// paytextBox
			// 
			this->paytextBox->Location = System::Drawing::Point(250, 575);
			this->paytextBox->Name = L"paytextBox";
			this->paytextBox->Size = System::Drawing::Size(34, 20);
			this->paytextBox->TabIndex = 16;
			// 
			// paylabel
			// 
			this->paylabel->AutoSize = true;
			this->paylabel->BackColor = System::Drawing::Color::Transparent;
			this->paylabel->Location = System::Drawing::Point(216, 578);
			this->paylabel->Name = L"paylabel";
			this->paylabel->Size = System::Drawing::Size(28, 13);
			this->paylabel->TabIndex = 17;
			this->paylabel->Text = L"Pay:";
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Main::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 1;
			this->timer2->Tick += gcnew System::EventHandler(this, &Main::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Interval = 1;
			this->timer3->Tick += gcnew System::EventHandler(this, &Main::timer3_Tick);
			// 
			// timer4
			// 
			this->timer4->Interval = 1;
			this->timer4->Tick += gcnew System::EventHandler(this, &Main::timer4_Tick);
			// 
			// timer5
			// 
			this->timer5->Interval = 1;
			this->timer5->Tick += gcnew System::EventHandler(this, &Main::timer5_Tick);
			// 
			// timer6
			// 
			this->timer6->Interval = 1;
			this->timer6->Tick += gcnew System::EventHandler(this, &Main::timer6_Tick);
			// 
			// finalbutton
			// 
			this->finalbutton->BackColor = System::Drawing::Color::AliceBlue;
			this->finalbutton->Location = System::Drawing::Point(746, 572);
			this->finalbutton->Name = L"finalbutton";
			this->finalbutton->Size = System::Drawing::Size(75, 23);
			this->finalbutton->TabIndex = 20;
			this->finalbutton->Text = L"Final";
			this->finalbutton->UseVisualStyleBackColor = false;
			this->finalbutton->Click += gcnew System::EventHandler(this, &Main::finalbutton_Click);
			// 
			// savebutton
			// 
			this->savebutton->BackColor = System::Drawing::Color::AliceBlue;
			this->savebutton->Location = System::Drawing::Point(774, 12);
			this->savebutton->Name = L"savebutton";
			this->savebutton->Size = System::Drawing::Size(75, 23);
			this->savebutton->TabIndex = 21;
			this->savebutton->Text = L"Save";
			this->savebutton->UseVisualStyleBackColor = false;
			this->savebutton->Click += gcnew System::EventHandler(this, &Main::savebutton_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(81, 401);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(49, 21);
			this->comboBox1->TabIndex = 22;
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(195, 401);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(49, 21);
			this->comboBox2->TabIndex = 23;
			// 
			// comboBox3
			// 
			this->comboBox3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(308, 401);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(49, 21);
			this->comboBox3->TabIndex = 24;
			// 
			// comboBox4
			// 
			this->comboBox4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(422, 401);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(49, 21);
			this->comboBox4->TabIndex = 25;
			// 
			// comboBox5
			// 
			this->comboBox5->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Location = System::Drawing::Point(540, 401);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(49, 21);
			this->comboBox5->TabIndex = 26;
			// 
			// comboBox6
			// 
			this->comboBox6->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Location = System::Drawing::Point(656, 401);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(49, 21);
			this->comboBox6->TabIndex = 27;
			// 
			// number6
			// 
			this->number6->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->number6->FormattingEnabled = true;
			this->number6->Location = System::Drawing::Point(656, 428);
			this->number6->Name = L"number6";
			this->number6->Size = System::Drawing::Size(49, 21);
			this->number6->TabIndex = 33;
			// 
			// number5
			// 
			this->number5->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->number5->FormattingEnabled = true;
			this->number5->Location = System::Drawing::Point(540, 428);
			this->number5->Name = L"number5";
			this->number5->Size = System::Drawing::Size(49, 21);
			this->number5->TabIndex = 32;
			// 
			// number4
			// 
			this->number4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->number4->FormattingEnabled = true;
			this->number4->Location = System::Drawing::Point(422, 428);
			this->number4->Name = L"number4";
			this->number4->Size = System::Drawing::Size(49, 21);
			this->number4->TabIndex = 31;
			// 
			// number3
			// 
			this->number3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->number3->FormattingEnabled = true;
			this->number3->Location = System::Drawing::Point(308, 428);
			this->number3->Name = L"number3";
			this->number3->Size = System::Drawing::Size(49, 21);
			this->number3->TabIndex = 30;
			// 
			// number2
			// 
			this->number2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->number2->FormattingEnabled = true;
			this->number2->Location = System::Drawing::Point(195, 428);
			this->number2->Name = L"number2";
			this->number2->Size = System::Drawing::Size(49, 21);
			this->number2->TabIndex = 29;
			// 
			// number1
			// 
			this->number1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->number1->FormattingEnabled = true;
			this->number1->Location = System::Drawing::Point(81, 428);
			this->number1->Name = L"number1";
			this->number1->Size = System::Drawing::Size(49, 21);
			this->number1->TabIndex = 28;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::AliceBlue;
			this->button1->Location = System::Drawing::Point(81, 473);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(57, 23);
			this->button1->TabIndex = 34;
			this->button1->Text = L"Change";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::AliceBlue;
			this->button2->Location = System::Drawing::Point(195, 473);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(57, 23);
			this->button2->TabIndex = 35;
			this->button2->Text = L"Change";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Main::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::AliceBlue;
			this->button3->Location = System::Drawing::Point(308, 473);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(57, 23);
			this->button3->TabIndex = 36;
			this->button3->Text = L"Change";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Main::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::AliceBlue;
			this->button4->Location = System::Drawing::Point(422, 473);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(57, 23);
			this->button4->TabIndex = 37;
			this->button4->Text = L"Change";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Main::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::AliceBlue;
			this->button5->Location = System::Drawing::Point(540, 473);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(57, 23);
			this->button5->TabIndex = 38;
			this->button5->Text = L"Change";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Main::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::AliceBlue;
			this->button6->Location = System::Drawing::Point(656, 473);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(57, 23);
			this->button6->TabIndex = 39;
			this->button6->Text = L"Change";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Main::button6_Click);
			// 
			// cheatbutton
			// 
			this->cheatbutton->BackColor = System::Drawing::Color::AliceBlue;
			this->cheatbutton->Location = System::Drawing::Point(774, 64);
			this->cheatbutton->Name = L"cheatbutton";
			this->cheatbutton->Size = System::Drawing::Size(75, 23);
			this->cheatbutton->TabIndex = 44;
			this->cheatbutton->Text = L"Happy";
			this->cheatbutton->UseVisualStyleBackColor = false;
			this->cheatbutton->Click += gcnew System::EventHandler(this, &Main::cheatbutton_Click);
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox8->ImageLocation = L"";
			this->pictureBox8->Location = System::Drawing::Point(112, 47);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(71, 96);
			this->pictureBox8->TabIndex = 45;
			this->pictureBox8->TabStop = false;
			// 
			// bigbutton
			// 
			this->bigbutton->BackColor = System::Drawing::Color::AliceBlue;
			this->bigbutton->Location = System::Drawing::Point(206, 42);
			this->bigbutton->Name = L"bigbutton";
			this->bigbutton->Size = System::Drawing::Size(75, 23);
			this->bigbutton->TabIndex = 46;
			this->bigbutton->Text = L"Big";
			this->bigbutton->UseVisualStyleBackColor = false;
			this->bigbutton->Click += gcnew System::EventHandler(this, &Main::bigbutton_Click);
			// 
			// smallbutton
			// 
			this->smallbutton->BackColor = System::Drawing::Color::AliceBlue;
			this->smallbutton->Location = System::Drawing::Point(206, 83);
			this->smallbutton->Name = L"smallbutton";
			this->smallbutton->Size = System::Drawing::Size(75, 23);
			this->smallbutton->TabIndex = 47;
			this->smallbutton->Text = L"Small";
			this->smallbutton->UseVisualStyleBackColor = false;
			this->smallbutton->Click += gcnew System::EventHandler(this, &Main::smallbutton_Click);
			// 
			// xbutton
			// 
			this->xbutton->BackColor = System::Drawing::Color::AliceBlue;
			this->xbutton->Location = System::Drawing::Point(206, 125);
			this->xbutton->Name = L"xbutton";
			this->xbutton->Size = System::Drawing::Size(75, 23);
			this->xbutton->TabIndex = 48;
			this->xbutton->Text = L"Don\'t play";
			this->xbutton->UseVisualStyleBackColor = false;
			this->xbutton->Click += gcnew System::EventHandler(this, &Main::xbutton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(186, 609);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(264, 13);
			this->label1->TabIndex = 49;
			this->label1->Text = L"Advanced feature 1: you can pay more than 20 credits";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(419, 536);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(383, 13);
			this->label2->TabIndex = 50;
			this->label2->Text = L"Advanced feature 2:  If you get a joker card, then you can use \"change\" button";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(27, 181);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(338, 13);
			this->label3->TabIndex = 51;
			this->label3->Text = L"Advanced feature 3: If you win, you can play this \"double-none\" game";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Location = System::Drawing::Point(580, 141);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(136, 13);
			this->label4->TabIndex = 52;
			this->label4->Text = L"Distinct feature1: Animation";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Location = System::Drawing::Point(759, 106);
			this->label5->MaximumSize = System::Drawing::Size(100, 250);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 156);
			this->label5->TabIndex = 53;
			this->label5->Text = L"Distinct feature2: Giving 500 credits then you can randomly pick one option: \n1. " 
				L"Get one more extra chance \n2. Get one more extra and swap chance \n3. get random " 
				L"one card be wildcard";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Lavender;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(861, 671);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->xbutton);
			this->Controls->Add(this->smallbutton);
			this->Controls->Add(this->bigbutton);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->cheatbutton);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->number6);
			this->Controls->Add(this->number5);
			this->Controls->Add(this->number4);
			this->Controls->Add(this->number3);
			this->Controls->Add(this->number2);
			this->Controls->Add(this->number1);
			this->Controls->Add(this->comboBox6);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->savebutton);
			this->Controls->Add(this->finalbutton);
			this->Controls->Add(this->paylabel);
			this->Controls->Add(this->paytextBox);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->exitbutton);
			this->Controls->Add(this->playbutton);
			this->Controls->Add(this->extrabutton);
			this->Controls->Add(this->newturnbutton);
			this->Controls->Add(this->swapbutton);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->Creditsvaluelabel);
			this->Controls->Add(this->acvaluelabel);
			this->Controls->Add(this->creditslabel);
			this->Controls->Add(this->aclabel);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Main";
			this->Text = L"Lucky888";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	///<Advanced feature3 function>
	private: System::Void bigbutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 this->bigbutton->Enabled = false;
				 this->smallbutton->Enabled = false;
				 this->xbutton->Enabled = false;
				 this->pictureBox8->ImageLocation = "images/" + gcnew String(guess->getType().c_str()) + guess->getValue() + ".jpg";
				 if(guess->getValue() >= 7)
				 {
					 MessageBox::Show("You win in this double-none-game, you can get " + gain*2 + " credits","Congratulations",MessageBoxButtons::OK);
					 writeCredits(gain*2);
				 }
				 else
				 {
					 MessageBox::Show("Sorry, you lose all the won credits!","Credits",MessageBoxButtons::OK);
				 }
				 delete guess;
				 this->newturnbutton->Enabled = true;
				 this->savebutton->Enabled = true;
			 }
	private: System::Void smallbutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 this->bigbutton->Enabled = false;
				 this->smallbutton->Enabled = false;
				 this->xbutton->Enabled = false;
				 this->pictureBox8->ImageLocation = "images/" + gcnew String(guess->getType().c_str()) + guess->getValue() + ".jpg";
				 if(guess->getValue() < 7)
				 {					 
					 MessageBox::Show("You win in this double-none-game, you can get " + gain*2 + " credits","Congratulations",MessageBoxButtons::OK);
					 writeCredits(gain*2);
				 }
				 else
				 {
					 MessageBox::Show("Sorry, you lose all the won credits!","Credits",MessageBoxButtons::OK);
				 }
				 delete guess;
				 this->savebutton->Enabled = true;
				 this->newturnbutton->Enabled = true;
			 }
	private: System::Void xbutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 this->bigbutton->Enabled = false;
				 this->smallbutton->Enabled = false;
				 this->xbutton->Enabled = false;
				 //Button to end this double-none-game
				 this->savebutton->Enabled = true;
				 this->newturnbutton->Enabled = true;
				 writeCredits(gain);
				 delete guess;
			 }
	///</Advanced feature3 function>
	///<Requirement function>
	private: System::Void newturnbutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 startGame();
			 }
	private: System::Void swapbutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				if(swap == false && extra == false)
				{
					swap = true;
					this->swapbutton->Enabled = false;
					for(int i=0;i<5;i++)
					{
						buttonarr[i]->Enabled = false;
						numberarr[i]->Enabled = false;
						comboarr[i]->Enabled = false;
						drawn[i] = giveCard();
						drawn[i].setPosition(i);
						this->picBox[i]->ImageLocation = "images/" + gcnew String(drawn[i].getType().c_str()) + drawn[i].getValue() + ".jpg";						
					}
					
					for(int i=0;i<6;i++)
					{
						picBox[i]->Location = System::Drawing::Point(650, 29);
					}
					this->timer1->Enabled = true;
					checkJoker();

					
				}// For 1st. step is swap

				else if(swap == false && extra == true)
				{
					swap = true;
					this->swapbutton->Enabled = false;
					drawn[5] = giveCard();
					drawn[5].setPosition(5);
					buttonarr[5]->Enabled = false;
					numberarr[5]->Enabled = false;
					comboarr[5]->Enabled = false;
					this->picBox[5]->ImageLocation = "images/" + gcnew String(drawn[5].getType().c_str()) + drawn[5].getValue() + ".jpg";


					picBox[5]->Location = System::Drawing::Point(650, 29);
					this->timer6->Enabled = true;
					checkJoker();
					
				}//For 1st. step is extra and 2nd. is swap, and then go to count the result
			 }
	private: System::Void extrabutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 extra = true;
				 this->extrabutton->Enabled = false;
				 this->swapbutton->Enabled = false;
				 drawn[5] = giveCard();
				 drawn[5].setPosition(5);
				 this->picBox[5]->ImageLocation = "images/" + gcnew String(drawn[5].getType().c_str()) + drawn[5].getValue() + ".jpg";
				 //For give a extra card

				 this->timer6->Enabled = true;
				 this->finalbutton->Enabled = true;
				 checkJoker();
			 }
	private: System::Void playbutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 
				 String^ str = this->paytextBox->Text;
				 char* payInput = (char*)Marshal::StringToHGlobalAnsi(str).ToPointer();				 	
				 pay = atoi(payInput);

				 if(pay > credits)
				 {
					 MessageBox::Show("You have no enough credits for paying!","Error",MessageBoxButtons::OK);
				 }
				 else if(pay < 20)
				 {
					 MessageBox::Show("Paid credits must be more than 20!","Error",MessageBoxButtons::OK);
				 }
				 else
				 {
					 this->playbutton->Enabled = false;
					 this->cheatbutton->Enabled = true;
					 this->savebutton->Enabled = false;
					 writeCredits(-pay);
					 for(int i=0;i<5;i++)
					 {
						 drawn[i] = giveCard();
						 drawn[i].setPosition(i);
						 this->picBox[i]->ImageLocation = "images/" + gcnew String(drawn[i].getType().c_str()) + drawn[i].getValue() + ".jpg";
					 }
					 checkJoker();
					 second = 0;
					 this->timer1->Enabled = true;
				 }
				 /*
				 drawn[0] = giveCard(1,9);
				 drawn[0].setPosition(0);

				 drawn[1] = giveCard(2,5);
				 drawn[1].setPosition(1);

				 drawn[2] = giveCard(0,12);
				 drawn[2].setPosition(2);

				 drawn[3] = giveCard(0,2);
				 drawn[3].setPosition(3);

				 drawn[4] = giveCard(0,14);
				 drawn[4].setPosition(4);

				 for(int i=0;i<5;i++)
				 {					 
					 this->picBox[i]->ImageLocation = "images/" + gcnew String(drawn[i].getType().c_str()) + drawn[i].getValue() + ".jpg";
				 }

				 */
				 Marshal::FreeHGlobal((IntPtr)payInput);
				 //System managed type delete operation
			 }// - credits and set the environment before swap and extra.	
	private: System::Void finalbutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 for(int i=0;i<6;i++)
				 {
					 comboarr[i]->Enabled = false;
					 numberarr[i]->Enabled = false;
					 buttonarr[i]->Enabled = false;
				 }
				 this->swapbutton->Enabled = false;
				 this->extrabutton->Enabled = false;
				 this->finalbutton->Enabled = false;
				 this->cheatbutton->Enabled = false;
				 countTurn();

				 //If win this turn, the none-double-game start
				 if(win == true)
				 {
					 this->xbutton->Enabled = true;
					 this->bigbutton->Enabled = true;
					 this->smallbutton->Enabled = true;
				 
					 this->pictureBox8->ImageLocation = "images/unknown.jpg";
					 guess = new PokerCard;
					 *guess = giveCard();
				 }
				 else
				 {
					 this->savebutton->Enabled = true;
					 this->newturnbutton->Enabled = true;
				 }
				 
			 }
	private: System::Void savebutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 ofstream fout;
				 char* ac = (char*)Marshal::StringToHGlobalAnsi(acstr).ToPointer();
				 char* pw = (char*)Marshal::StringToHGlobalAnsi(pwstr).ToPointer();
				 string saveac(ac);
				 string savepw(pw);

				 
				 if(saveac!="New player")
				 {
					 fout.open(saveac + ".txt");
					 fout << saveac << endl;
					 fout << savepw << endl;
					 fout << credits;
					 fout.close();
				 }
				 else
				 {
					registration^ reg = gcnew registration(credits);
					reg->ShowDialog();
					acstr = reg->getAcName();
					this->acvaluelabel->Text = acstr;
				 }

				 //if this ac have already exist,save directly.
				 //else, go to registration page for regsistering

				 Marshal::FreeHGlobal((IntPtr)ac);
				 Marshal::FreeHGlobal((IntPtr)pw);
				 MessageBox::Show("Saved XD!","Sucess",MessageBoxButtons::OK);
			 }
	///</Requirement function>
	///<Advanced feature 2 and distinct feature1,2 function>
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 changeCard(0);
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 changeCard(1);
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 changeCard(2);
			 }
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 changeCard(3);
			 }
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 changeCard(4);
			 }
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 changeCard(5);
			 }
	private: System::Void cheatbutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 this->cheatbutton->Enabled = false;
				 if(credits<500)
				 {
					 MessageBox::Show("No enough credits","Wrong",MessageBoxButtons::OK);
				 }
				 else
				 {
					 writeCredits(-500);
					 int num = rand()% 3;

					 switch(num)
					 {
						case 0:
							extra = false;
							this->extrabutton->Enabled = true;
							MessageBox::Show("You got one more ""Extra"" chance!","Congratulations!",MessageBoxButtons::OK);
							break;
						case 1:
							swap = false;
							extra = false;
							this->swapbutton->Enabled = true;
							MessageBox::Show("You got one more ""Swap"" and ""Extra"" chance!","Congratulations!",MessageBoxButtons::OK);
							break;
						case 2:
							int good = rand()% 6;
							comboarr[good]->Enabled = true;
							numberarr[good]->Enabled = true;
							buttonarr[good]->Enabled = true;
							MessageBox::Show("You got one card can be ""wildcard"" chance!","Congratulations!",MessageBoxButtons::OK);
							break;
					 }
				 }
				 

			 }	
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 second += 7;
				 if(second+29 < 271)
				 {
					 double ydiff = second + 29 - 29;
					 double a = 29 - 270;
					 double b = 650 - 75;
					 double slope = a/b;
					 double ans = ydiff/slope + 650;
					 this->pictureBox1->Location = System::Drawing::Point((int)ans, second+29);
				 }
				 else
				 {
					this->timer1->Enabled = false;
					second = 0;
					this->timer2->Enabled = true;
				 }
				 //Start giving card one, and then start giving card two
			 }
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {
			 second += 7;
			 if(second+29 < 271)
			 {
				 double ydiff = second + 29 - 29;
				 double a = 29 - 270;
				 double b = 650 - 189;
				 double slope = a/b;
				 double ans = ydiff/slope + 650;
				 this->pictureBox2->Location = System::Drawing::Point((int)ans, second+29);
			 }
			 else
			 {
				this->timer2->Enabled = false;
				second = 0;
				this->timer3->Enabled = true;
			 }
			 //Start giving card two, and then start giving card three
		 }
	private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {
			 second += 7;
			 if(second+29 < 271)
			 {
				 double ydiff = second + 29 - 29;
				 double a = 29 - 270;
				 double b = 650 - 302;
				 double slope = a/b;
				 double ans = ydiff/slope + 650;
				 this->pictureBox3->Location = System::Drawing::Point((int)ans, second+29);
			 }
			 else
			 {
				this->timer3->Enabled = false;
				second = 0;
				this->timer4->Enabled = true;
			 }
			 //Start giving card three, and then start giving card four
		 }
	private: System::Void timer4_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {
			 second += 7;
			 if(second+29 < 271)
			 {
				 double ydiff = second + 29 - 29;
				 double a = 29 - 270;
				 double b = 650 - 416;
				 double slope = a/b;
				 double ans = ydiff/slope + 650;
				 this->pictureBox4->Location = System::Drawing::Point((int)ans, second+29);
			 }
			 else
			 {
				this->timer4->Enabled = false;
				second = 0;
				this->timer5->Enabled = true;
			 }
			 //Start giving card four, and then start giving card five
		 }
	private: System::Void timer5_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {
			 second += 7;
			 if(second+29 < 271)
			 {
				 double ydiff = second + 29 - 29;
				 double a = 29 - 270;
				 double b = 650 - 534;
				 double slope = a/b;
				 double ans = ydiff/slope + 650;
				 this->pictureBox5->Location = System::Drawing::Point((int)ans, second+29);
			 }
			 else
			 {
				if(swap == false)
				{
					this->swapbutton->Enabled = true;
				}
				else
				{
					this->swapbutton->Enabled = false;
					checkJoker();
				}
				this->extrabutton->Enabled = true;
				this->timer5->Enabled = false;
				second = 0;
				//Start giving card five


				if(extra == true && swap == true)
				{
					this->swapbutton->Enabled = false;
					this->extrabutton->Enabled = false;
				}//if 1st. is swap,then 2nd is extra and then go to count the result


			 }

			 

		 }
	private: System::Void timer6_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {
			 second += 7;
			 if(second+29 < 271)
			 {				 
				 this->pictureBox6->Location = System::Drawing::Point(650, second+29);
			 }
			 else
			 {
				this->timer6->Enabled = false;
				second = 0;
				this->swapbutton->Enabled = true;
				if(extra == true && swap == true)
				{

					this->swapbutton->Enabled = false;
					this->extrabutton->Enabled = false;
				}//Start giving card six
				//if 1st. is swap,then 2nd is extra and then go to count the result
			 }
		 }
	///</Advanced feature 2 and distinct feature1,2 function>
	private: System::Void exitbutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 this->Close();
				 Application::Exit();
			 }
	};
}

 


