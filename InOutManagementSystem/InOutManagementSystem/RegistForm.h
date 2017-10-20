#pragma once

#include "procedureRegist.h"

namespace InOutManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// RegistForm の概要
	/// </summary>
	public ref class RegistForm : public System::Windows::Forms::Form
	{
	public:
		RegistForm(void)
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
		~RegistForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePickerBirth;
	private: System::Windows::Forms::TextBox^  textBoxTel;
	protected:



	private: System::Windows::Forms::TextBox^  textBoxAddress;
	private: System::Windows::Forms::TextBox^  textBoxLastName;


	private: System::Windows::Forms::Label^  labelBirthDay;
	private: System::Windows::Forms::Label^  labelTel;




	private: System::Windows::Forms::Label^  labelAddress;
	private: System::Windows::Forms::Label^  labelLastName;


	private: System::Windows::Forms::Label^  labelID;
	private: System::Windows::Forms::TextBox^  textBoxID;
	private: System::Windows::Forms::ComboBox^  comboBoxAffili;


	private: System::Windows::Forms::ComboBox^  comboBoxCharacter;



	private: System::Windows::Forms::ComboBox^  comboBoxCast;
	private: System::Windows::Forms::Label^  labelAttr;


	private: System::Windows::Forms::Label^  labelCast;
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::ComboBox^  comboBoxAuth;

	private: System::Windows::Forms::Label^  labelCharacter;
	private: System::Windows::Forms::Label^  labelAuthority;
	private: System::Windows::Forms::TextBox^  textBoxPassword;
	private: System::Windows::Forms::Label^  labelPassword;
	private: System::Windows::Forms::TextBox^  textBoxFirstName;

	private: System::Windows::Forms::Label^  labelFirstName;
	private: System::Windows::Forms::Label^  labelGroup;

	private: System::Windows::Forms::Label^  labelAffili;
	private: System::Windows::Forms::ComboBox^  comboBoxGroup;



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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->comboBoxGroup = (gcnew System::Windows::Forms::ComboBox());
			this->labelGroup = (gcnew System::Windows::Forms::Label());
			this->labelAffili = (gcnew System::Windows::Forms::Label());
			this->textBoxFirstName = (gcnew System::Windows::Forms::TextBox());
			this->labelFirstName = (gcnew System::Windows::Forms::Label());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->comboBoxAuth = (gcnew System::Windows::Forms::ComboBox());
			this->labelCharacter = (gcnew System::Windows::Forms::Label());
			this->labelAuthority = (gcnew System::Windows::Forms::Label());
			this->comboBoxCharacter = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxCast = (gcnew System::Windows::Forms::ComboBox());
			this->labelAttr = (gcnew System::Windows::Forms::Label());
			this->labelCast = (gcnew System::Windows::Forms::Label());
			this->comboBoxAffili = (gcnew System::Windows::Forms::ComboBox());
			this->dateTimePickerBirth = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBoxTel = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAddress = (gcnew System::Windows::Forms::TextBox());
			this->textBoxLastName = (gcnew System::Windows::Forms::TextBox());
			this->labelBirthDay = (gcnew System::Windows::Forms::Label());
			this->labelTel = (gcnew System::Windows::Forms::Label());
			this->labelAddress = (gcnew System::Windows::Forms::Label());
			this->labelLastName = (gcnew System::Windows::Forms::Label());
			this->labelID = (gcnew System::Windows::Forms::Label());
			this->textBoxID = (gcnew System::Windows::Forms::TextBox());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->comboBoxGroup);
			this->panel1->Controls->Add(this->labelGroup);
			this->panel1->Controls->Add(this->labelAffili);
			this->panel1->Controls->Add(this->textBoxFirstName);
			this->panel1->Controls->Add(this->labelFirstName);
			this->panel1->Controls->Add(this->textBoxPassword);
			this->panel1->Controls->Add(this->labelPassword);
			this->panel1->Controls->Add(this->comboBoxAuth);
			this->panel1->Controls->Add(this->labelCharacter);
			this->panel1->Controls->Add(this->labelAuthority);
			this->panel1->Controls->Add(this->comboBoxCharacter);
			this->panel1->Controls->Add(this->comboBoxCast);
			this->panel1->Controls->Add(this->labelAttr);
			this->panel1->Controls->Add(this->labelCast);
			this->panel1->Controls->Add(this->comboBoxAffili);
			this->panel1->Controls->Add(this->dateTimePickerBirth);
			this->panel1->Controls->Add(this->textBoxTel);
			this->panel1->Controls->Add(this->textBoxAddress);
			this->panel1->Controls->Add(this->textBoxLastName);
			this->panel1->Controls->Add(this->labelBirthDay);
			this->panel1->Controls->Add(this->labelTel);
			this->panel1->Controls->Add(this->labelAddress);
			this->panel1->Controls->Add(this->labelLastName);
			this->panel1->Controls->Add(this->labelID);
			this->panel1->Controls->Add(this->textBoxID);
			this->panel1->Location = System::Drawing::Point(4, 71);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(582, 352);
			this->panel1->TabIndex = 2;
			// 
			// comboBoxGroup
			// 
			this->comboBoxGroup->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxGroup->FormattingEnabled = true;
			this->comboBoxGroup->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"第一グループ", L"第二グループ", L"第三グループ" });
			this->comboBoxGroup->Location = System::Drawing::Point(370, 141);
			this->comboBoxGroup->Name = L"comboBoxGroup";
			this->comboBoxGroup->Size = System::Drawing::Size(121, 20);
			this->comboBoxGroup->TabIndex = 8;
			// 
			// labelGroup
			// 
			this->labelGroup->AutoSize = true;
			this->labelGroup->Location = System::Drawing::Point(317, 141);
			this->labelGroup->Name = L"labelGroup";
			this->labelGroup->Size = System::Drawing::Size(43, 12);
			this->labelGroup->TabIndex = 24;
			this->labelGroup->Text = L"グループ";
			// 
			// labelAffili
			// 
			this->labelAffili->AutoSize = true;
			this->labelAffili->Location = System::Drawing::Point(317, 96);
			this->labelAffili->Name = L"labelAffili";
			this->labelAffili->Size = System::Drawing::Size(29, 12);
			this->labelAffili->TabIndex = 23;
			this->labelAffili->Text = L"所属";
			// 
			// textBoxFirstName
			// 
			this->textBoxFirstName->Location = System::Drawing::Point(67, 79);
			this->textBoxFirstName->Name = L"textBoxFirstName";
			this->textBoxFirstName->Size = System::Drawing::Size(147, 19);
			this->textBoxFirstName->TabIndex = 2;
			// 
			// labelFirstName
			// 
			this->labelFirstName->AutoSize = true;
			this->labelFirstName->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelFirstName->Location = System::Drawing::Point(14, 79);
			this->labelFirstName->Name = L"labelFirstName";
			this->labelFirstName->Size = System::Drawing::Size(37, 15);
			this->labelFirstName->TabIndex = 21;
			this->labelFirstName->Text = L"名前";
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Location = System::Drawing::Point(86, 289);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(141, 19);
			this->textBoxPassword->TabIndex = 5;
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Location = System::Drawing::Point(20, 296);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(52, 12);
			this->labelPassword->TabIndex = 8;
			this->labelPassword->Text = L"パスワード";
			// 
			// comboBoxAuth
			// 
			this->comboBoxAuth->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxAuth->FormattingEnabled = true;
			this->comboBoxAuth->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"閲覧者", L"管理者" });
			this->comboBoxAuth->Location = System::Drawing::Point(405, 233);
			this->comboBoxAuth->Name = L"comboBoxAuth";
			this->comboBoxAuth->Size = System::Drawing::Size(121, 20);
			this->comboBoxAuth->TabIndex = 10;
			// 
			// labelCharacter
			// 
			this->labelCharacter->AutoSize = true;
			this->labelCharacter->Location = System::Drawing::Point(353, 274);
			this->labelCharacter->Name = L"labelCharacter";
			this->labelCharacter->Size = System::Drawing::Size(29, 12);
			this->labelCharacter->TabIndex = 19;
			this->labelCharacter->Text = L"人物";
			// 
			// labelAuthority
			// 
			this->labelAuthority->AutoSize = true;
			this->labelAuthority->Location = System::Drawing::Point(353, 236);
			this->labelAuthority->Name = L"labelAuthority";
			this->labelAuthority->Size = System::Drawing::Size(29, 12);
			this->labelAuthority->TabIndex = 17;
			this->labelAuthority->Text = L"権限";
			// 
			// comboBoxCharacter
			// 
			this->comboBoxCharacter->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCharacter->FormattingEnabled = true;
			this->comboBoxCharacter->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"一般", L"入館拒否", L"要注意人物" });
			this->comboBoxCharacter->Location = System::Drawing::Point(405, 271);
			this->comboBoxCharacter->Name = L"comboBoxCharacter";
			this->comboBoxCharacter->Size = System::Drawing::Size(121, 20);
			this->comboBoxCharacter->TabIndex = 11;
			// 
			// comboBoxCast
			// 
			this->comboBoxCast->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCast->FormattingEnabled = true;
			this->comboBoxCast->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"正社員", L"パート", L"部長" });
			this->comboBoxCast->Location = System::Drawing::Point(370, 194);
			this->comboBoxCast->Name = L"comboBoxCast";
			this->comboBoxCast->Size = System::Drawing::Size(121, 20);
			this->comboBoxCast->TabIndex = 9;
			// 
			// labelAttr
			// 
			this->labelAttr->AutoSize = true;
			this->labelAttr->Location = System::Drawing::Point(309, 236);
			this->labelAttr->Name = L"labelAttr";
			this->labelAttr->Size = System::Drawing::Size(29, 12);
			this->labelAttr->TabIndex = 16;
			this->labelAttr->Text = L"属性";
			// 
			// labelCast
			// 
			this->labelCast->AutoSize = true;
			this->labelCast->Location = System::Drawing::Point(315, 197);
			this->labelCast->Name = L"labelCast";
			this->labelCast->Size = System::Drawing::Size(29, 12);
			this->labelCast->TabIndex = 14;
			this->labelCast->Text = L"役職";
			// 
			// comboBoxAffili
			// 
			this->comboBoxAffili->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxAffili->FormattingEnabled = true;
			this->comboBoxAffili->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"営業", L"総務", L"開発" });
			this->comboBoxAffili->Location = System::Drawing::Point(370, 93);
			this->comboBoxAffili->Name = L"comboBoxAffili";
			this->comboBoxAffili->Size = System::Drawing::Size(121, 20);
			this->comboBoxAffili->TabIndex = 7;
			// 
			// dateTimePickerBirth
			// 
			this->dateTimePickerBirth->Location = System::Drawing::Point(361, 27);
			this->dateTimePickerBirth->Name = L"dateTimePickerBirth";
			this->dateTimePickerBirth->Size = System::Drawing::Size(200, 19);
			this->dateTimePickerBirth->TabIndex = 6;
			// 
			// textBoxTel
			// 
			this->textBoxTel->Location = System::Drawing::Point(83, 225);
			this->textBoxTel->Name = L"textBoxTel";
			this->textBoxTel->Size = System::Drawing::Size(144, 19);
			this->textBoxTel->TabIndex = 4;
			// 
			// textBoxAddress
			// 
			this->textBoxAddress->Location = System::Drawing::Point(8, 126);
			this->textBoxAddress->Multiline = true;
			this->textBoxAddress->Name = L"textBoxAddress";
			this->textBoxAddress->Size = System::Drawing::Size(248, 76);
			this->textBoxAddress->TabIndex = 3;
			// 
			// textBoxLastName
			// 
			this->textBoxLastName->Location = System::Drawing::Point(67, 54);
			this->textBoxLastName->Name = L"textBoxLastName";
			this->textBoxLastName->Size = System::Drawing::Size(147, 19);
			this->textBoxLastName->TabIndex = 1;
			// 
			// labelBirthDay
			// 
			this->labelBirthDay->AutoSize = true;
			this->labelBirthDay->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelBirthDay->Location = System::Drawing::Point(277, 29);
			this->labelBirthDay->Name = L"labelBirthDay";
			this->labelBirthDay->Size = System::Drawing::Size(67, 15);
			this->labelBirthDay->TabIndex = 10;
			this->labelBirthDay->Text = L"生年月日";
			// 
			// labelTel
			// 
			this->labelTel->AutoSize = true;
			this->labelTel->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelTel->Location = System::Drawing::Point(5, 228);
			this->labelTel->Name = L"labelTel";
			this->labelTel->Size = System::Drawing::Size(67, 15);
			this->labelTel->TabIndex = 6;
			this->labelTel->Text = L"電話番号";
			// 
			// labelAddress
			// 
			this->labelAddress->AutoSize = true;
			this->labelAddress->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelAddress->Location = System::Drawing::Point(19, 108);
			this->labelAddress->Name = L"labelAddress";
			this->labelAddress->Size = System::Drawing::Size(37, 15);
			this->labelAddress->TabIndex = 4;
			this->labelAddress->Text = L"住所";
			// 
			// labelLastName
			// 
			this->labelLastName->AutoSize = true;
			this->labelLastName->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelLastName->Location = System::Drawing::Point(14, 54);
			this->labelLastName->Name = L"labelLastName";
			this->labelLastName->Size = System::Drawing::Size(37, 15);
			this->labelLastName->TabIndex = 2;
			this->labelLastName->Text = L"苗字";
			// 
			// labelID
			// 
			this->labelID->AutoSize = true;
			this->labelID->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelID->Location = System::Drawing::Point(22, 29);
			this->labelID->Name = L"labelID";
			this->labelID->Size = System::Drawing::Size(21, 15);
			this->labelID->TabIndex = 0;
			this->labelID->Text = L"ID";
			// 
			// textBoxID
			// 
			this->textBoxID->Location = System::Drawing::Point(67, 29);
			this->textBoxID->Name = L"textBoxID";
			this->textBoxID->Size = System::Drawing::Size(147, 19);
			this->textBoxID->TabIndex = 0;
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(470, 12);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(95, 53);
			this->buttonCancel->TabIndex = 1;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(365, 12);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(95, 53);
			this->buttonOK->TabIndex = 0;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &RegistForm::buttonOK_Click);
			// 
			// RegistForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(598, 435);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->panel1);
			this->Name = L"RegistForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"RegistForm";
			this->Load += gcnew System::EventHandler(this, &RegistForm::RegistForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		Constants* registConstant;

		/*
		関数名:setData
		概要:入力されているデータを格納する関数
		引数:procedureRegist procedureregist 格納先の値
		返却値:無し
		作成日:10月16日(月)
		作成者:成田修之
		*/
		void setData(procedureRegist* procedureregist) {
			//ユーザーのIDをメンバに保管
			procedureregist->userId = registConstant->StrToc_str(this->textBoxID->Text);
			//入力されたユーザー名を格納する
			procedureregist->userLastName = registConstant->StrToc_str(this->textBoxLastName->Text);
			procedureregist->userFirstName = registConstant->StrToc_str(this->textBoxFirstName->Text);
			//入力された電話番号を格納する
			procedureregist->telNo = registConstant->StrToc_str(this->textBoxTel->Text);
			if (procedureregist->telNo.length() > 11) {
				throw std::exception("電話番号が不正です\nハイフンを入れず11桁までの半角で入力してください");
			}
			//入力された住所を格納する
			procedureregist->address = registConstant->StrToc_str(this->textBoxAddress->Text);
			if (procedureregist->address.length() > 96) {
				throw std::exception("住所が長すぎます");
			}
			//パスワード入力欄に入力された値を入れる
			procedureregist->password = registConstant->StrToc_str(this->textBoxPassword->Text);
			if (procedureregist->password.length() < 4 || 16 < procedureregist->password.length()) {
				throw std::exception("パスワードは半角で4文字以上16文字以下で入力してください");
			}


			//選択された生年月日を取得
			DateTime date = dateTimePickerBirth->Value;
			//年を取得
			int year = date.Year;
			//月を取得
			int month = date.Month;
			//日にちを取得
			int day = date.Day;

			//一つにまとめて格納する
			procedureregist->birthday = year * 10000 + month * 100 + day;

			//グループを選択されたインデックスで格納する
			procedureregist->setGroup(comboBoxGroup->SelectedIndex);
			//役職を選択されたインデックスで格納する
			procedureregist->setCast(comboBoxCast->SelectedIndex);
			//所属を選択されたインデックスで格納する
			procedureregist->setAffli(comboBoxAffili->SelectedIndex);
			//前から選ばれたインデックス番目のビットを立てる
			procedureregist->setAuth(comboBoxAuth->SelectedIndex);
			//2バイト目の前から選ばれたインデックス番目のビットを立てる
			procedureregist->setChara(comboBoxCharacter->SelectedIndex);	
		}

	private:
		/*
		関数名:buttonOK_Click
		概要:情報の入力が完了しOKボタンが押下されたときのイベント
		引数:イベントの引数
		返却値:無し
		作成日:10月16日(月)
		作成者:成田修之
		*/
		System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			//現在の情報で作成していいかの確認
			Windows::Forms::DialogResult dr = MessageBox::Show("現在の情報で登録します。\nよろしいですか", "登録前確認", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);

			//キャンセルが押されたとき
			if (dr == Windows::Forms::DialogResult::Cancel) {
				//処理を行わずに辞める
				return;
			}

			//登録処理を行うクラスのインスタンスを生成
			procedureRegist* procedureregist = new procedureRegist();

			try {
				//入力されたデータ群をメンバにセットする
				setData(procedureregist);
				//書き込みするための準備の関数を実行する
				procedureregist->init();
				//準備ができたのでカードをかざすように促す
				MessageBox::Show("カードをかざしてください", "書き込み開始", MessageBoxButtons::OK, MessageBoxIcon::None);
				//カードへの書き込みを開始する
				procedureregist->registData();
				MessageBox::Show("書き込み完了", "", MessageBoxButtons::OK, MessageBoxIcon::None);
				this->Close();
			}
			//例外が発生したとき
			catch (std::exception& e) {
				//メッセージを送出して例外を伝える
				MessageBox::Show(gcnew String(e.what()), "エラー", MessageBoxButtons::OK, MessageBoxIcon::Hand);

			}
			//CLIの例外が発生したとき
			catch (Exception^ e) {
				//不正な入力を通知
				MessageBox::Show("不正な入力があります。", "", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				
			}
			//必ず行う処理
			finally {
				//カードリーダの解放処理を行う
				procedureregist->clear();
			}
		}


	private: 
		System::Void RegistForm_Load(System::Object^  sender, System::EventArgs^  e) {

//デバッグコード
//textBoxID->Text = "1";		
//textBoxName->Text = "成田　修之";
//textBoxAddress->Text = "埼玉県所沢市上山口138-26"; 
//textBoxTel->Text = "08013116165";

			this->comboBoxAuth->SelectedIndex = 0;
			this->comboBoxCast->SelectedIndex = 0;
			this->comboBoxGroup->SelectedIndex = 0;
			this->comboBoxAffili->SelectedIndex = 0;
			this->comboBoxCharacter->SelectedIndex = 0;
		}
};
}
