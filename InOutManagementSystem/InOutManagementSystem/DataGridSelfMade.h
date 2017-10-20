#pragma once

#include "ChainData.h"
#include "Cell.h"

namespace narita {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	ref class DataGridSelfMade
	{
	private:
		PictureBox^ pictureBox;	//描画したものを配置するピクチャーボックス
		Bitmap^ canvas;			//描画先のオブジェクト
		Graphics^ graphic;		//描画するためのオブジェクト
		Pen^ cellFramePen;		//セルの枠を書くためのペンオブジェクト
		Font^ font;				//フォント


		int _colCount;	//列数
		int _rowCount;	//行数



	public:
		int cellWidth;	//セルの幅
		int cellHeight;	//セルの高さ

		ChainData* cell;

		TextBox^ text;	//テキストボックス
						//列数のプロパティー
		property int colCount {
			int get() {
				return _colCount;
			}
			void set(int col) {
				_colCount = col;
			}
		}
		//行数のプロパティー
		property int rowCount {
			int get() {
				return _rowCount;
			}
			void set(int row) {
				_rowCount = row;
			}
		}
		//現在選択中のセル
		Cell^ currentCell;

		//コンストラクタ
		DataGridSelfMade(PictureBox^ pictureBox);

		//クリックされたときの動作
		Void cell_click(EventArgs^ e);
		Void cell_click(int row, int col);
		Void cell_click(Cell^ cell);

		//指定の行、列に引数の色のセルを描画する関数
		Void drawCell(int row, int col, Brush^ color);
		//引数がセルの時
		Void drawCell(Cell^ cell, Brush ^ color);

		//行ごとの描画を行う関数
		Void drawRow(int row, Brush^ color);
		//引数がセルの時(オーバーライド)
		Void drawRow(Cell^ cell, Brush^ color);

		//全体を一から描画するメソッド
		Void Paint();
		//表部分のデータをクリアする関数
		//Void Clear();

	private:/*
		Void textboxEnter(System::Object^  sender, Windows::Forms::KeyEventArgs^  e);
		Void textboxLostFocus(System::Object ^ sender, EventArgs ^ e);*/
	};

}

