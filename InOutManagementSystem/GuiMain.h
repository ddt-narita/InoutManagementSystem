#pragma once

#include "Constants.h"
#include "procedureInOut.h"
#include "RegistForm.h"
#include "InoutForm.h"
#include "PassCheckForm.h"

namespace {
	Constants constants;
};

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
			this->SuspendLayout();
			// 
			// GuiMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(446, 321);
			this->Name = L"GuiMain";
			this->Text = L"GuiMain";
			this->Load += gcnew System::EventHandler(this, &GuiMain::GuiMain_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:

	private:
		System::Void GuiMain_Load(System::Object^  sender, System::EventArgs^  e) {
			//カード待ちを開始する
			while(true) {
				//かざされるカードごとのデータを処理するクラスのインスタンスを生成する
				procedureInOut* procedureinout = new procedureInOut();
				//カードリーダとの初期化を行う
				procedureinout->init();
				//カードがかざされるまで待つ
				procedureinout->card.getStatusChange(INFINITE);
				//編集フォームのインスタンスを生成する
				inoutForm^ edit = gcnew inoutForm();
				//フォームのデータに
				edit->inoutData = procedureinout;
				//フォームを表示する
				edit->ShowDialog();
				//次の人のデータを取得するためこのクラスは必要なしで削除する
				delete procedureinout;
			}

		}
	};
}
