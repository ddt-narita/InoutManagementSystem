#pragma once

#include "DataManager.h"
#include "DataGridSelfMade.h"

namespace InOutManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// inoutForm の概要
	/// </summary>
	public ref class inoutForm : public System::Windows::Forms::Form
	{
	public:
		inoutForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~inoutForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Label^  labelID;

	private: System::Windows::Forms::TextBox^  textBoxID;
	private: System::Windows::Forms::Label^  labelLastName;
	private: System::Windows::Forms::TextBox^  textBoxLastName;






	private: System::Windows::Forms::Label^  labelBirthday;

	private: System::Windows::Forms::TextBox^  textBoxTell;




	private: System::Windows::Forms::Label^  labelTell;
	private: System::Windows::Forms::Label^  labelAddress;
	private: System::Windows::Forms::TextBox^  textBoxAddress;
	private: System::Windows::Forms::ComboBox^  comboBoxAffili;


	private: System::Windows::Forms::ComboBox^  comboBoxCast;
	private: System::Windows::Forms::ComboBox^  comboBoxAuthority;
	private: System::Windows::Forms::Label^  labelAffili;








	private: System::Windows::Forms::Label^  labelCast;
	private: System::Windows::Forms::Label^  labelAttr;
	private: System::Windows::Forms::Label^  labelAuthority;
	private: System::Windows::Forms::Label^  labelCharacter;
	private: System::Windows::Forms::ComboBox^  comboBoxCharacter;





	private: System::Windows::Forms::Label^  labelInoutYM;
	private: System::Windows::Forms::TextBox^  textBoxInoutY;
	private: System::Windows::Forms::Label^  labelInoutY;
	private: System::Windows::Forms::TextBox^  textBoxInoutM;
	private: System::Windows::Forms::Label^  labelInoutM;




	private: System::Windows::Forms::DateTimePicker^  dateTimePickerBirthday;






	private: System::Windows::Forms::Label^  labelFirstName;
	private: System::Windows::Forms::TextBox^  textBoxFirstName;
	private: System::Windows::Forms::Label^  labelGroup;
	private: System::Windows::Forms::ComboBox^  comboBoxGroup;
	private: System::Windows::Forms::Button^  buttonIn;
	private: System::Windows::Forms::Button^  buttonOut;
	private: System::Windows::Forms::Button^  buttonInoutView;











	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelID = (gcnew System::Windows::Forms::Label());
			this->textBoxID = (gcnew System::Windows::Forms::TextBox());
			this->labelLastName = (gcnew System::Windows::Forms::Label());
			this->textBoxLastName = (gcnew System::Windows::Forms::TextBox());
			this->labelBirthday = (gcnew System::Windows::Forms::Label());
			this->textBoxTell = (gcnew System::Windows::Forms::TextBox());
			this->labelTell = (gcnew System::Windows::Forms::Label());
			this->labelAddress = (gcnew System::Windows::Forms::Label());
			this->textBoxAddress = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxAffili = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxCast = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxAuthority = (gcnew System::Windows::Forms::ComboBox());
			this->labelAffili = (gcnew System::Windows::Forms::Label());
			this->labelCast = (gcnew System::Windows::Forms::Label());
			this->labelAttr = (gcnew System::Windows::Forms::Label());
			this->labelAuthority = (gcnew System::Windows::Forms::Label());
			this->labelCharacter = (gcnew System::Windows::Forms::Label());
			this->comboBoxCharacter = (gcnew System::Windows::Forms::ComboBox());
			this->labelInoutYM = (gcnew System::Windows::Forms::Label());
			this->textBoxInoutY = (gcnew System::Windows::Forms::TextBox());
			this->labelInoutY = (gcnew System::Windows::Forms::Label());
			this->textBoxInoutM = (gcnew System::Windows::Forms::TextBox());
			this->labelInoutM = (gcnew System::Windows::Forms::Label());
			this->dateTimePickerBirthday = (gcnew System::Windows::Forms::DateTimePicker());
			this->labelFirstName = (gcnew System::Windows::Forms::Label());
			this->textBoxFirstName = (gcnew System::Windows::Forms::TextBox());
			this->labelGroup = (gcnew System::Windows::Forms::Label());
			this->comboBoxGroup = (gcnew System::Windows::Forms::ComboBox());
			this->buttonIn = (gcnew System::Windows::Forms::Button());
			this->buttonOut = (gcnew System::Windows::Forms::Button());
			this->buttonInoutView = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelID
			// 
			this->labelID->AutoSize = true;
			this->labelID->Location = System::Drawing::Point(50, 108);
			this->labelID->Name = L"labelID";
			this->labelID->Size = System::Drawing::Size(16, 12);
			this->labelID->TabIndex = 2;
			this->labelID->Text = L"ID";
			// 
			// textBoxID
			// 
			this->textBoxID->Location = System::Drawing::Point(72, 105);
			this->textBoxID->Name = L"textBoxID";
			this->textBoxID->Size = System::Drawing::Size(144, 19);
			this->textBoxID->TabIndex = 0;
			// 
			// labelLastName
			// 
			this->labelLastName->AutoSize = true;
			this->labelLastName->Location = System::Drawing::Point(37, 143);
			this->labelLastName->Name = L"labelLastName";
			this->labelLastName->Size = System::Drawing::Size(29, 12);
			this->labelLastName->TabIndex = 4;
			this->labelLastName->Text = L"苗字";
			// 
			// textBoxLastName
			// 
			this->textBoxLastName->Location = System::Drawing::Point(72, 136);
			this->textBoxLastName->Name = L"textBoxLastName";
			this->textBoxLastName->Size = System::Drawing::Size(144, 19);
			this->textBoxLastName->TabIndex = 1;
			// 
			// labelBirthday
			// 
			this->labelBirthday->AutoSize = true;
			this->labelBirthday->Location = System::Drawing::Point(14, 202);
			this->labelBirthday->Name = L"labelBirthday";
			this->labelBirthday->Size = System::Drawing::Size(53, 12);
			this->labelBirthday->TabIndex = 6;
			this->labelBirthday->Text = L"生年月日";
			// 
			// textBoxTell
			// 
			this->textBoxTell->Location = System::Drawing::Point(73, 232);
			this->textBoxTell->Name = L"textBoxTell";
			this->textBoxTell->Size = System::Drawing::Size(144, 19);
			this->textBoxTell->TabIndex = 4;
			// 
			// labelTell
			// 
			this->labelTell->AutoSize = true;
			this->labelTell->Location = System::Drawing::Point(14, 235);
			this->labelTell->Name = L"labelTell";
			this->labelTell->Size = System::Drawing::Size(53, 12);
			this->labelTell->TabIndex = 11;
			this->labelTell->Text = L"電話番号";
			// 
			// labelAddress
			// 
			this->labelAddress->AutoSize = true;
			this->labelAddress->Location = System::Drawing::Point(263, 121);
			this->labelAddress->Name = L"labelAddress";
			this->labelAddress->Size = System::Drawing::Size(29, 12);
			this->labelAddress->TabIndex = 12;
			this->labelAddress->Text = L"住所";
			// 
			// textBoxAddress
			// 
			this->textBoxAddress->Location = System::Drawing::Point(304, 118);
			this->textBoxAddress->Multiline = true;
			this->textBoxAddress->Name = L"textBoxAddress";
			this->textBoxAddress->Size = System::Drawing::Size(276, 60);
			this->textBoxAddress->TabIndex = 7;
			// 
			// comboBoxAffili
			// 
			this->comboBoxAffili->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxAffili->FormattingEnabled = true;
			this->comboBoxAffili->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"営業", L"総務", L"開発" });
			this->comboBoxAffili->Location = System::Drawing::Point(304, 184);
			this->comboBoxAffili->Name = L"comboBoxAffili";
			this->comboBoxAffili->Size = System::Drawing::Size(121, 20);
			this->comboBoxAffili->TabIndex = 8;
			// 
			// comboBoxCast
			// 
			this->comboBoxCast->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCast->FormattingEnabled = true;
			this->comboBoxCast->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"正社員", L"パート", L"部長" });
			this->comboBoxCast->Location = System::Drawing::Point(306, 237);
			this->comboBoxCast->Name = L"comboBoxCast";
			this->comboBoxCast->Size = System::Drawing::Size(121, 20);
			this->comboBoxCast->TabIndex = 10;
			// 
			// comboBoxAuthority
			// 
			this->comboBoxAuthority->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxAuthority->FormattingEnabled = true;
			this->comboBoxAuthority->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"閲覧者", L"管理者" });
			this->comboBoxAuthority->Location = System::Drawing::Point(348, 263);
			this->comboBoxAuthority->Name = L"comboBoxAuthority";
			this->comboBoxAuthority->Size = System::Drawing::Size(121, 20);
			this->comboBoxAuthority->TabIndex = 11;
			// 
			// labelAffili
			// 
			this->labelAffili->AutoSize = true;
			this->labelAffili->Location = System::Drawing::Point(263, 187);
			this->labelAffili->Name = L"labelAffili";
			this->labelAffili->Size = System::Drawing::Size(29, 12);
			this->labelAffili->TabIndex = 17;
			this->labelAffili->Text = L"所属";
			// 
			// labelCast
			// 
			this->labelCast->AutoSize = true;
			this->labelCast->Location = System::Drawing::Point(265, 240);
			this->labelCast->Name = L"labelCast";
			this->labelCast->Size = System::Drawing::Size(29, 12);
			this->labelCast->TabIndex = 18;
			this->labelCast->Text = L"役職";
			// 
			// labelAttr
			// 
			this->labelAttr->AutoSize = true;
			this->labelAttr->Location = System::Drawing::Point(265, 266);
			this->labelAttr->Name = L"labelAttr";
			this->labelAttr->Size = System::Drawing::Size(29, 12);
			this->labelAttr->TabIndex = 19;
			this->labelAttr->Text = L"属性";
			// 
			// labelAuthority
			// 
			this->labelAuthority->AutoSize = true;
			this->labelAuthority->Location = System::Drawing::Point(304, 266);
			this->labelAuthority->Name = L"labelAuthority";
			this->labelAuthority->Size = System::Drawing::Size(29, 12);
			this->labelAuthority->TabIndex = 20;
			this->labelAuthority->Text = L"権限";
			// 
			// labelCharacter
			// 
			this->labelCharacter->AutoSize = true;
			this->labelCharacter->Location = System::Drawing::Point(304, 292);
			this->labelCharacter->Name = L"labelCharacter";
			this->labelCharacter->Size = System::Drawing::Size(29, 12);
			this->labelCharacter->TabIndex = 21;
			this->labelCharacter->Text = L"人物";
			// 
			// comboBoxCharacter
			// 
			this->comboBoxCharacter->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCharacter->FormattingEnabled = true;
			this->comboBoxCharacter->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"無し", L"入館拒否", L"要注意人物" });
			this->comboBoxCharacter->Location = System::Drawing::Point(348, 289);
			this->comboBoxCharacter->Name = L"comboBoxCharacter";
			this->comboBoxCharacter->Size = System::Drawing::Size(121, 20);
			this->comboBoxCharacter->TabIndex = 12;
			// 
			// labelInoutYM
			// 
			this->labelInoutYM->AutoSize = true;
			this->labelInoutYM->Location = System::Drawing::Point(11, 280);
			this->labelInoutYM->Name = L"labelInoutYM";
			this->labelInoutYM->Size = System::Drawing::Size(65, 12);
			this->labelInoutYM->TabIndex = 24;
			this->labelInoutYM->Text = L"入退館年月";
			// 
			// textBoxInoutY
			// 
			this->textBoxInoutY->Location = System::Drawing::Point(92, 277);
			this->textBoxInoutY->Name = L"textBoxInoutY";
			this->textBoxInoutY->Size = System::Drawing::Size(36, 19);
			this->textBoxInoutY->TabIndex = 5;
			// 
			// labelInoutY
			// 
			this->labelInoutY->AutoSize = true;
			this->labelInoutY->Location = System::Drawing::Point(134, 280);
			this->labelInoutY->Name = L"labelInoutY";
			this->labelInoutY->Size = System::Drawing::Size(17, 12);
			this->labelInoutY->TabIndex = 26;
			this->labelInoutY->Text = L"年";
			// 
			// textBoxInoutM
			// 
			this->textBoxInoutM->Location = System::Drawing::Point(157, 277);
			this->textBoxInoutM->Name = L"textBoxInoutM";
			this->textBoxInoutM->Size = System::Drawing::Size(36, 19);
			this->textBoxInoutM->TabIndex = 6;
			// 
			// labelInoutM
			// 
			this->labelInoutM->AutoSize = true;
			this->labelInoutM->Location = System::Drawing::Point(199, 280);
			this->labelInoutM->Name = L"labelInoutM";
			this->labelInoutM->Size = System::Drawing::Size(17, 12);
			this->labelInoutM->TabIndex = 28;
			this->labelInoutM->Text = L"月";
			// 
			// dateTimePickerBirthday
			// 
			this->dateTimePickerBirthday->Location = System::Drawing::Point(73, 197);
			this->dateTimePickerBirthday->Name = L"dateTimePickerBirthday";
			this->dateTimePickerBirthday->Size = System::Drawing::Size(144, 19);
			this->dateTimePickerBirthday->TabIndex = 3;
			// 
			// labelFirstName
			// 
			this->labelFirstName->AutoSize = true;
			this->labelFirstName->Location = System::Drawing::Point(37, 166);
			this->labelFirstName->Name = L"labelFirstName";
			this->labelFirstName->Size = System::Drawing::Size(29, 12);
			this->labelFirstName->TabIndex = 37;
			this->labelFirstName->Text = L"名前";
			// 
			// textBoxFirstName
			// 
			this->textBoxFirstName->Location = System::Drawing::Point(73, 163);
			this->textBoxFirstName->Name = L"textBoxFirstName";
			this->textBoxFirstName->Size = System::Drawing::Size(144, 19);
			this->textBoxFirstName->TabIndex = 2;
			// 
			// labelGroup
			// 
			this->labelGroup->AutoSize = true;
			this->labelGroup->Location = System::Drawing::Point(249, 213);
			this->labelGroup->Name = L"labelGroup";
			this->labelGroup->Size = System::Drawing::Size(43, 12);
			this->labelGroup->TabIndex = 39;
			this->labelGroup->Text = L"グループ";
			// 
			// comboBoxGroup
			// 
			this->comboBoxGroup->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxGroup->FormattingEnabled = true;
			this->comboBoxGroup->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"第一グループ", L"第二グループ", L"第三グループ" });
			this->comboBoxGroup->Location = System::Drawing::Point(306, 210);
			this->comboBoxGroup->Name = L"comboBoxGroup";
			this->comboBoxGroup->Size = System::Drawing::Size(121, 20);
			this->comboBoxGroup->TabIndex = 9;
			// 
			// buttonIn
			// 
			this->buttonIn->Location = System::Drawing::Point(12, 12);
			this->buttonIn->Name = L"buttonIn";
			this->buttonIn->Size = System::Drawing::Size(73, 46);
			this->buttonIn->TabIndex = 40;
			this->buttonIn->Text = L"入館";
			this->buttonIn->UseVisualStyleBackColor = true;
			this->buttonIn->Click += gcnew System::EventHandler(this, &inoutForm::buttonInOut_Click);
			// 
			// buttonOut
			// 
			this->buttonOut->Location = System::Drawing::Point(91, 12);
			this->buttonOut->Name = L"buttonOut";
			this->buttonOut->Size = System::Drawing::Size(72, 46);
			this->buttonOut->TabIndex = 41;
			this->buttonOut->Text = L"退館";
			this->buttonOut->UseVisualStyleBackColor = true;
			this->buttonOut->Click += gcnew System::EventHandler(this, &inoutForm::buttonInOut_Click);
			// 
			// buttonInoutView
			// 
			this->buttonInoutView->Location = System::Drawing::Point(306, 12);
			this->buttonInoutView->Name = L"buttonInoutView";
			this->buttonInoutView->Size = System::Drawing::Size(59, 46);
			this->buttonInoutView->TabIndex = 42;
			this->buttonInoutView->Text = L"入退館一覧";
			this->buttonInoutView->UseVisualStyleBackColor = true;
			this->buttonInoutView->Click += gcnew System::EventHandler(this, &inoutForm::buttonInoutView_Click);
			// 
			// inoutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(596, 339);
			this->Controls->Add(this->buttonInoutView);
			this->Controls->Add(this->buttonOut);
			this->Controls->Add(this->buttonIn);
			this->Controls->Add(this->comboBoxGroup);
			this->Controls->Add(this->labelGroup);
			this->Controls->Add(this->textBoxFirstName);
			this->Controls->Add(this->labelFirstName);
			this->Controls->Add(this->dateTimePickerBirthday);
			this->Controls->Add(this->labelInoutM);
			this->Controls->Add(this->textBoxInoutM);
			this->Controls->Add(this->labelInoutY);
			this->Controls->Add(this->textBoxInoutY);
			this->Controls->Add(this->labelInoutYM);
			this->Controls->Add(this->comboBoxCharacter);
			this->Controls->Add(this->labelCharacter);
			this->Controls->Add(this->labelAuthority);
			this->Controls->Add(this->labelAttr);
			this->Controls->Add(this->labelCast);
			this->Controls->Add(this->labelAffili);
			this->Controls->Add(this->comboBoxAuthority);
			this->Controls->Add(this->comboBoxCast);
			this->Controls->Add(this->comboBoxAffili);
			this->Controls->Add(this->textBoxAddress);
			this->Controls->Add(this->labelAddress);
			this->Controls->Add(this->labelTell);
			this->Controls->Add(this->textBoxTell);
			this->Controls->Add(this->labelBirthday);
			this->Controls->Add(this->textBoxLastName);
			this->Controls->Add(this->labelLastName);
			this->Controls->Add(this->textBoxID);
			this->Controls->Add(this->labelID);
			this->Name = L"inoutForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EditForm";
			this->Load += gcnew System::EventHandler(this, &inoutForm::EditForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		procedureInOut* inoutData;

	private:

		System::Void applyControls() {
			//基本情報を文字列に変えて与える
			textBoxID->Text = gcnew String(inoutData->userId.c_str());
			//苗字を渡す
			textBoxLastName->Text = gcnew String(inoutData->userLastName.c_str());
			//名前を渡す
			textBoxFirstName->Text = gcnew String(inoutData->userFirstName.c_str());
			//電話番号を渡す
			textBoxTell->Text = gcnew String(inoutData->telNo.c_str());
			//住所を渡す
			textBoxAddress->Text = gcnew String(inoutData->address.c_str());

			//追加情報をコンボボックスの選択値として格納する
			comboBoxAffili->SelectedIndex = inoutData->getSelectedAffli();
			comboBoxGroup->SelectedIndex = inoutData->getSelectedGroup();
			comboBoxCast->SelectedIndex = inoutData->getSelectedCast();
			comboBoxAuthority->SelectedIndex = inoutData->getSelectedAuth();
			comboBoxCharacter->SelectedIndex = inoutData->getSelectedChara();


			//誕生日の値から年月日を計算して取得
			int year = inoutData->birthday / 10000;
			int month = (inoutData->birthday / 100) - (year * 100);
			int day = (inoutData->birthday) - (year * 10000) - (month * 100);

			//取得した年月日で日付を作製
			DateTime date(year, month, day);
			//フォームの誕生日選択の値として渡す
			dateTimePickerBirthday->Value = date;

			//入退の年月を渡す
			textBoxInoutY->Text = inoutData->getInoutY().ToString();
			textBoxInoutM->Text = inoutData->getInoutM().ToString();
			//フォームの各情報を読み込み専用にする
			setReadOnly();

		}



		System::Void EditForm_Load(System::Object^  sender, System::EventArgs^  e) {

			inoutData->card.connectCard();
			try {
				//カードのデータを読み込む
				inoutData->readCardData();
				//IDのチェックを行う
				inoutData->checkId();
				//人物のチェックを行う
				inoutData->checkCharacter();
				//ファイルから前回までの情報を取得してメンバに格納する
				inoutData->readFileData();
				//前回までのデータをカードへと書き出す
				inoutData->writeCard();
				//フォーム上に
				applyControls();
				//入館状態のチェックを行う
				inoutData->inoutCheck();
			}
			//例外が発生したとき
			catch (std::exception& e) {
				//例外に添えられたメッセージをメッセージボックスで警告を出す
				MessageBox::Show(gcnew String(e.what()), "警告", MessageBoxButtons::OK, MessageBoxIcon::Hand);
			}
		}

		/*
		関数名:setReadOnly
		概要:編集可能なフォームを編集不可にする(表示のみにする)
		引数:なし
		返却値:なし
		作成日:10月18日(水)
		作成者:成田修之
		*/
		void setReadOnly() {
			//テキストボックスを読み専用にする
			textBoxID->ReadOnly = true;			//ID
			textBoxFirstName->ReadOnly = true;	//名前
			textBoxLastName->ReadOnly = true;	//苗字
			textBoxAddress->ReadOnly = true;	//住所
			textBoxTell->ReadOnly = true;		//電話
			textBoxInoutY->ReadOnly = true;		//年
			textBoxInoutM->ReadOnly = true;		//月

			//コンボボックスをドロップダウンできなくする
			comboBoxGroup->Enabled = false;		//グループ
			comboBoxAffili->Enabled = false;	//所属
			comboBoxCast->Enabled = false;		//役職
			comboBoxAuthority->Enabled = false;	//権限
			comboBoxCharacter->Enabled = false;	//人物

			//日付選択コントロールも選択できなくする
			dateTimePickerBirthday->Enabled = false;
		}


	private:
		System::Void buttonInOut_Click(System::Object^  sender, System::EventArgs^  e) {
			//入館か退館のイベントを起こしたボタンを取得する
			Button^ inoutButton = (Button^)sender;
			//入館ボタンからなら入退館処理のクラスに入館の値を、退館ボタンなら退館の値を渡す
			inoutData->inout = (inoutButton->Name == "buttonIn" ? INOUT::In : INOUT::Out);
			try {
				//入退館処理を行う
				inoutData->InOut();
				//例外に添えられたメッセージをメッセージボックスで警告を出す
				MessageBox::Show("ファイルへの書き込み完了！", "完了", MessageBoxButtons::OK, MessageBoxIcon::None);
			}
			catch (std::exception& e) {
				//例外に添えられたメッセージをメッセージボックスで警告を出す
				MessageBox::Show(gcnew String(e.what()), "警告", MessageBoxButtons::OK, MessageBoxIcon::Hand);
			}
		}
	private: System::Void buttonInoutView_Click(System::Object^  sender, System::EventArgs^  e) {


	}
};
}
