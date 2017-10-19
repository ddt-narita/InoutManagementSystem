#pragma once

namespace InOutManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// PassCheckForm の概要
	/// </summary>
	public ref class PassCheckForm : public System::Windows::Forms::Form
	{
	public:
		PassCheckForm(void)
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
		~PassCheckForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelMessage;
	private: System::Windows::Forms::TextBox^  textBoxInputPass;
	protected:

	protected:

	private: System::Windows::Forms::Label^  labelID;
	private: System::Windows::Forms::Label^  labelName;
	private: System::Windows::Forms::Button^  buttonOK;

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
			this->labelMessage = (gcnew System::Windows::Forms::Label());
			this->textBoxInputPass = (gcnew System::Windows::Forms::TextBox());
			this->labelID = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelMessage
			// 
			this->labelMessage->AutoSize = true;
			this->labelMessage->Location = System::Drawing::Point(46, 60);
			this->labelMessage->Name = L"labelMessage";
			this->labelMessage->Size = System::Drawing::Size(133, 12);
			this->labelMessage->TabIndex = 0;
			this->labelMessage->Text = L"パスワードを入力して下さい";
			// 
			// textBoxInputPass
			// 
			this->textBoxInputPass->Location = System::Drawing::Point(12, 75);
			this->textBoxInputPass->Name = L"textBoxInputPass";
			this->textBoxInputPass->Size = System::Drawing::Size(208, 19);
			this->textBoxInputPass->TabIndex = 1;
			// 
			// labelID
			// 
			this->labelID->AutoSize = true;
			this->labelID->Location = System::Drawing::Point(28, 30);
			this->labelID->Name = L"labelID";
			this->labelID->Size = System::Drawing::Size(0, 12);
			this->labelID->TabIndex = 2;
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Location = System::Drawing::Point(129, 30);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(0, 12);
			this->labelName->TabIndex = 3;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(76, 104);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 4;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &PassCheckForm::buttonOK_Click);
			// 
			// PassCheckForm
			// 
			this->AcceptButton = this->buttonOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(233, 139);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->labelID);
			this->Controls->Add(this->textBoxInputPass);
			this->Controls->Add(this->labelMessage);
			this->Name = L"PassCheckForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"PassCheckForm";
			this->Load += gcnew System::EventHandler(this, &PassCheckForm::PassCheckForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		int id;
		String^ name;
		String^ password;
		bool Judge;


	private:
		System::Void PassCheckForm_Load(System::Object^  sender, System::EventArgs^  e) {
			labelID->Text = "ID:" + id.ToString();
			labelName->Text = "名前:" + name;
			Judge = false;
		}
		
		System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			if (textBoxInputPass->Text == password) {
				Judge = true;
				this->Close();
			}
			else {
				MessageBox::Show("パスワードが違います", "", MessageBoxButtons::OK, MessageBoxIcon::Hand);
			}
		}
	};
}
