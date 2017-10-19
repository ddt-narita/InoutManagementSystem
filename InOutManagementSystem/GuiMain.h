#pragma once

#include "Constants.h"
#include "procedureInOut.h"
#include "RegistForm.h"
#include "EditForm.h"
#include "PassCheckForm.h"

namespace InOutManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// GuiMain の概要
	/// </summary>
	public ref class GuiMain : public System::Windows::Forms::Form
	{
	public:
		GuiMain(void)
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
		~GuiMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonIn;
	private: System::Windows::Forms::Button^  buttonOut;
	private: System::Windows::Forms::Button^  buttonRegister;
	private: System::Windows::Forms::Label^  labelIn;

	private: System::Windows::Forms::Label^  labelOut;


	private: System::Windows::Forms::Button^  buttonDataView;
	private: System::Windows::Forms::Button^  buttonEdit;
	private: System::Windows::Forms::Label^  labelCautionNeed;





	protected:


	protected:

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
			this->buttonIn = (gcnew System::Windows::Forms::Button());
			this->buttonOut = (gcnew System::Windows::Forms::Button());
			this->buttonRegister = (gcnew System::Windows::Forms::Button());
			this->labelIn = (gcnew System::Windows::Forms::Label());
			this->labelOut = (gcnew System::Windows::Forms::Label());
			this->buttonDataView = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->labelCautionNeed = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonIn
			// 
			this->buttonIn->Location = System::Drawing::Point(323, 12);
			this->buttonIn->Name = L"buttonIn";
			this->buttonIn->Size = System::Drawing::Size(69, 56);
			this->buttonIn->TabIndex = 0;
			this->buttonIn->Text = L"入館";
			this->buttonIn->UseVisualStyleBackColor = true;
			this->buttonIn->Click += gcnew System::EventHandler(this, &GuiMain::buttonInOut_Click);
			// 
			// buttonOut
			// 
			this->buttonOut->Location = System::Drawing::Point(398, 12);
			this->buttonOut->Name = L"buttonOut";
			this->buttonOut->Size = System::Drawing::Size(69, 56);
			this->buttonOut->TabIndex = 1;
			this->buttonOut->Text = L"退館";
			this->buttonOut->UseVisualStyleBackColor = true;
			this->buttonOut->Click += gcnew System::EventHandler(this, &GuiMain::buttonInOut_Click);
			// 
			// buttonRegister
			// 
			this->buttonRegister->Location = System::Drawing::Point(24, 12);
			this->buttonRegister->Name = L"buttonRegister";
			this->buttonRegister->Size = System::Drawing::Size(69, 56);
			this->buttonRegister->TabIndex = 2;
			this->buttonRegister->Text = L"登録";
			this->buttonRegister->UseVisualStyleBackColor = true;
			this->buttonRegister->Click += gcnew System::EventHandler(this, &GuiMain::buttonRegister_Click);
			// 
			// labelIn
			// 
			this->labelIn->AutoSize = true;
			this->labelIn->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 42, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelIn->Location = System::Drawing::Point(146, 170);
			this->labelIn->Name = L"labelIn";
			this->labelIn->Size = System::Drawing::Size(136, 56);
			this->labelIn->TabIndex = 3;
			this->labelIn->Text = L"入館";
			this->labelIn->Visible = false;
			// 
			// labelOut
			// 
			this->labelOut->AutoSize = true;
			this->labelOut->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 42, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelOut->Location = System::Drawing::Point(146, 170);
			this->labelOut->Name = L"labelOut";
			this->labelOut->Size = System::Drawing::Size(136, 56);
			this->labelOut->TabIndex = 4;
			this->labelOut->Text = L"退館";
			this->labelOut->Visible = false;
			// 
			// buttonDataView
			// 
			this->buttonDataView->Location = System::Drawing::Point(99, 12);
			this->buttonDataView->Name = L"buttonDataView";
			this->buttonDataView->Size = System::Drawing::Size(69, 56);
			this->buttonDataView->TabIndex = 6;
			this->buttonDataView->Text = L"情報表示";
			this->buttonDataView->UseVisualStyleBackColor = true;
			this->buttonDataView->Click += gcnew System::EventHandler(this, &GuiMain::buttonDataView_Click);
			// 
			// buttonEdit
			// 
			this->buttonEdit->Location = System::Drawing::Point(174, 12);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(69, 56);
			this->buttonEdit->TabIndex = 7;
			this->buttonEdit->Text = L"編集";
			this->buttonEdit->UseVisualStyleBackColor = true;
			this->buttonEdit->Visible = false;
			// 
			// labelCautionNeed
			// 
			this->labelCautionNeed->AutoSize = true;
			this->labelCautionNeed->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelCautionNeed->Location = System::Drawing::Point(65, 246);
			this->labelCautionNeed->Name = L"labelCautionNeed";
			this->labelCautionNeed->Size = System::Drawing::Size(308, 48);
			this->labelCautionNeed->TabIndex = 8;
			this->labelCautionNeed->Text = L"！要注意人物";
			this->labelCautionNeed->Visible = false;
			// 
			// GuiMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(472, 315);
			this->Controls->Add(this->labelCautionNeed);
			this->Controls->Add(this->buttonEdit);
			this->Controls->Add(this->buttonDataView);
			this->Controls->Add(this->labelOut);
			this->Controls->Add(this->labelIn);
			this->Controls->Add(this->buttonRegister);
			this->Controls->Add(this->buttonOut);
			this->Controls->Add(this->buttonIn);
			this->Name = L"GuiMain";
			this->Text = L"GuiMain";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		procedureInOut* procedureInout;

		/*
		関数名:labelsOff
		概要:ラベル群を非表示にする
		引数:無し
		返却値:無し
		作成日:10月18日(水)
		作成者:成田修之
		*/
		Void labelsOff() {
			//ラベルをすべて非表示に
			this->labelIn->Visible = false;
			this->labelOut->Visible = false;
			this->labelCautionNeed->Visible = false;
		}

		/*
		関数名:CheckCharacter
		概要:人物のチェックを行う
		引数:なし
		返却値:なし
		作成日:10月18日(水)
		作成者:成田修之
		*/
		Void CheckCharacter() {
			//人物の値を取得する
			int character = procedureInout->getCharacter();

			//取得した値で分岐
			switch (character) {
				//無しの時
			case 0:
				//何もせずに抜ける
				break;
				//入館拒否者の時
			case 1:
				//例外を送出する
				throw std::exception();
				///抜ける
				break;
				//要注意人物の時
			case 2:
				//そのことを示すラベルを表示する
				labelCautionNeed->Visible = true;
				//抜ける
				break;
			}
		}


	private:
		System::Void buttonInOut_Click(System::Object^  sender, System::EventArgs^  e) {
			//このイベントを起こしたボタンを取得する
			Button^ inoutButton = (Button^)sender;
			//今出ているラベル群を見えなくする
			labelsOff();
			//入退館処理を行うクラスのインスタンスを生成する
			procedureInout = new procedureInOut();
			//押されたボタンによって入退処理クラスに渡す値をそれぞれにする
			procedureInout->inout = (inoutButton->Name == "buttonIn" ? INOUT::In : INOUT::Out);
			try {
				//カードリーダ等の初期化を行う
				procedureInout->init();
				//入退館処理を実行する
				procedureInout->InOut();
				CheckCharacter();
				//入館ボタンからの時
				if (inoutButton->Name == "buttonIn") {
					//入館を示すあたいを格納
					labelIn->Visible = true;
				}
				//退館ボタンからの時
				else {
					//退館を示す値を格納
					labelOut->Visible = true;
				}
			}
			catch (std::exception& e) {
				//エラーのメッセージをそのまま表示する
				MessageBox::Show(gcnew String(e.what()), "エラー", MessageBoxButtons::OK, MessageBoxIcon::Hand);
			}
			finally{
				//カードリーダのクリア処理
				procedureInout->clear();
			}
		}

	private:
		System::Void buttonRegister_Click(System::Object^  sender, System::EventArgs^  e) {
			RegistForm^ registform = gcnew RegistForm();
			registform->ShowDialog();
		}

	private:
		System::Void buttonDataView_Click(System::Object^  sender, System::EventArgs^  e) {

			//カードをかざす指示を出す
			Windows::Forms::DialogResult dr = MessageBox::Show("情報を表示したいカードをかざしてください", "", MessageBoxButtons::OKCancel, MessageBoxIcon::None);

			if (dr == Windows::Forms::DialogResult::Cancel) {
				return;
			}

			//カードのデータを取得するためのオブジェクトを生成
			DataManager* cardData = new DataManager();

			try {
				//カードリーダの初期化を行う
				cardData->init();
				//カードのIDのみ読み込む
				cardData->readCardId();
				//カードのデータをファイルから取得する
				cardData->readFileData();
				//パスワードをチェックする
				password_check(cardData);

				//編集フォームを作製する
				EditForm^ editForm = gcnew EditForm();
				//編集フォームにカードのデータを渡す
				editForm->editData = cardData;
				//表示ボタンから来たことを示す値を渡す
				editForm->buttonFrom = 1;
				//編集フォームを表示する
				editForm->ShowDialog();
			}
			catch (std::exception& e) {
				MessageBox::Show(gcnew String(e.what()), "", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}



		Void password_check(DataManager* cardData) {
			PassCheckForm^ passform = gcnew PassCheckForm();

			//
			passform->id = cardData->userId;
			passform->name = gcnew String(cardData->userName.c_str());
			passform->password = gcnew String(cardData->password.c_str());
			passform->ShowDialog();

			//
			if (!passform->Judge) {
				//
				throw std::exception("表示処理が中断されました。");
			}
		}
	};
}
