#pragma once

#include"DataGridSelfMade.h"

namespace InOutManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// InOutView の概要
	/// </summary>
	public ref class InOutView : public System::Windows::Forms::Form
	{
	public:
		InOutView(void)
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
		~InOutView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::PictureBox^  pictureBoxOutData;

	private: System::Windows::Forms::PictureBox^  pictureBoxInData;

	private: System::Windows::Forms::Label^  labelInDay;
	private: System::Windows::Forms::Label^  labelInHour;
	private: System::Windows::Forms::Label^  labelInMinute;
	private: System::Windows::Forms::Label^  labelOutMinute;




	private: System::Windows::Forms::Label^  labelOutHour;

	private: System::Windows::Forms::Label^  labelOutDay;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::Button^  buttonEdit;




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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxOutData = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxInData = (gcnew System::Windows::Forms::PictureBox());
			this->labelInDay = (gcnew System::Windows::Forms::Label());
			this->labelInHour = (gcnew System::Windows::Forms::Label());
			this->labelInMinute = (gcnew System::Windows::Forms::Label());
			this->labelOutMinute = (gcnew System::Windows::Forms::Label());
			this->labelOutHour = (gcnew System::Windows::Forms::Label());
			this->labelOutDay = (gcnew System::Windows::Forms::Label());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOutData))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxInData))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->pictureBoxOutData);
			this->panel1->Controls->Add(this->pictureBoxInData);
			this->panel1->Location = System::Drawing::Point(12, 110);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(425, 299);
			this->panel1->TabIndex = 0;
			this->panel1->Visible = false;
			// 
			// pictureBoxOutData
			// 
			this->pictureBoxOutData->Location = System::Drawing::Point(205, 3);
			this->pictureBoxOutData->Name = L"pictureBoxOutData";
			this->pictureBoxOutData->Size = System::Drawing::Size(21, 14);
			this->pictureBoxOutData->TabIndex = 1;
			this->pictureBoxOutData->TabStop = false;
			this->pictureBoxOutData->Visible = false;
			// 
			// pictureBoxInData
			// 
			this->pictureBoxInData->Location = System::Drawing::Point(3, 3);
			this->pictureBoxInData->Name = L"pictureBoxInData";
			this->pictureBoxInData->Size = System::Drawing::Size(20, 14);
			this->pictureBoxInData->TabIndex = 0;
			this->pictureBoxInData->TabStop = false;
			this->pictureBoxInData->Visible = false;
			// 
			// labelInDay
			// 
			this->labelInDay->AutoSize = true;
			this->labelInDay->Location = System::Drawing::Point(20, 95);
			this->labelInDay->Name = L"labelInDay";
			this->labelInDay->Size = System::Drawing::Size(29, 12);
			this->labelInDay->TabIndex = 1;
			this->labelInDay->Text = L"日付";
			// 
			// labelInHour
			// 
			this->labelInHour->AutoSize = true;
			this->labelInHour->Location = System::Drawing::Point(74, 95);
			this->labelInHour->Name = L"labelInHour";
			this->labelInHour->Size = System::Drawing::Size(17, 12);
			this->labelInHour->TabIndex = 2;
			this->labelInHour->Text = L"時";
			// 
			// labelInMinute
			// 
			this->labelInMinute->AutoSize = true;
			this->labelInMinute->Location = System::Drawing::Point(113, 95);
			this->labelInMinute->Name = L"labelInMinute";
			this->labelInMinute->Size = System::Drawing::Size(17, 12);
			this->labelInMinute->TabIndex = 3;
			this->labelInMinute->Text = L"分";
			// 
			// labelOutMinute
			// 
			this->labelOutMinute->AutoSize = true;
			this->labelOutMinute->Location = System::Drawing::Point(315, 95);
			this->labelOutMinute->Name = L"labelOutMinute";
			this->labelOutMinute->Size = System::Drawing::Size(17, 12);
			this->labelOutMinute->TabIndex = 6;
			this->labelOutMinute->Text = L"分";
			// 
			// labelOutHour
			// 
			this->labelOutHour->AutoSize = true;
			this->labelOutHour->Location = System::Drawing::Point(274, 95);
			this->labelOutHour->Name = L"labelOutHour";
			this->labelOutHour->Size = System::Drawing::Size(17, 12);
			this->labelOutHour->TabIndex = 5;
			this->labelOutHour->Text = L"時";
			// 
			// labelOutDay
			// 
			this->labelOutDay->AutoSize = true;
			this->labelOutDay->Location = System::Drawing::Point(222, 95);
			this->labelOutDay->Name = L"labelOutDay";
			this->labelOutDay->Size = System::Drawing::Size(29, 12);
			this->labelOutDay->TabIndex = 4;
			this->labelOutDay->Text = L"日付";
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(307, 12);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(62, 54);
			this->buttonOK->TabIndex = 7;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &InOutView::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(375, 12);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(62, 54);
			this->buttonCancel->TabIndex = 8;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &InOutView::buttonCansel_Click);
			// 
			// buttonEdit
			// 
			this->buttonEdit->Location = System::Drawing::Point(12, 18);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(75, 43);
			this->buttonEdit->TabIndex = 9;
			this->buttonEdit->Text = L"編集";
			this->buttonEdit->UseVisualStyleBackColor = true;
			// 
			// InOutView
			// 
			this->AcceptButton = this->buttonOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(449, 421);
			this->Controls->Add(this->buttonEdit);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->labelOutMinute);
			this->Controls->Add(this->labelOutHour);
			this->Controls->Add(this->labelOutDay);
			this->Controls->Add(this->labelInMinute);
			this->Controls->Add(this->labelInHour);
			this->Controls->Add(this->labelInDay);
			this->Controls->Add(this->panel1);
			this->Name = L"InOutView";
			this->Text = L"InOutView";
			this->Load += gcnew System::EventHandler(this, &InOutView::InOutView_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOutData))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxInData))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		narita::DataGridSelfMade^ gridIn;
		narita::DataGridSelfMade^ gridOut;
		procedureInOut* procedureinout;




	private:

		System::Void buttonCansel_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
		}

		System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
		}

		/*
		関数名:
		概要:
		引数:
		返却値:
		作成日:
		作成者:
		*/
		System::Void InOutView_Load(System::Object^  sender, System::EventArgs^  e) {
			gridIn = gcnew narita::DataGridSelfMade(pictureBoxInData);
			gridOut = gcnew narita::DataGridSelfMade(pictureBoxOutData);

			gridIn->cell->applyVecData(procedureinout->inTime);
		}
	};
}
