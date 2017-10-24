#include "DataGridSelfMade.h"



using namespace narita;

/*
関数名:コンストラクタ
概要:描画先のピクチャーボックスを受け取ってこれからはそこへ配置する
引数:PictureBox^ pictureBox　描画したものの配置先
返却値:無し
作成日:9月9日
作成者:成田修之
*/
DataGridSelfMade::DataGridSelfMade(PictureBox^ pictureBox)
{
	//受け取った描画したものを配置するオブジェクトをメンバに共有
	(this->pictureBox) = pictureBox;
	//セルごとのクラス初期化
	//初期列数
	colCount = 1;
	//初期行数
	rowCount = 1;
	//セルの幅
	cellWidth = 60;
	//セルの高さ
	cellHeight = 20;
	//カレントセルを作成
	currentCell = gcnew narita::Cell();
	cell = new ChainData();

	//セルの枠を描くペンオブジェクトを作成
	cellFramePen = gcnew Pen(Color::Black, 3);
	//文字列を書くときのフォント
	font = gcnew Font("ＭＳ ゴシック", 9);

	//描画対象のイメージオブジェクト
	this->canvas = gcnew Bitmap(this->pictureBox->Width - 1, this->pictureBox->Height - 1);
	//作成したイメージオブジェクトをピクチャボックスに配置
	this->pictureBox->Image = this->canvas;
	//ピクチャボックス描画対象に描くためのオブジェクトを作成
	this->graphic = Graphics::FromImage(this->pictureBox->Image);
	//選択されたセルに表示するテキストボックスを表示する
	text = gcnew TextBox();
	text->Multiline = true;
	text->AutoSize = false;
	text->ImeMode = ImeMode::Off;
	pictureBox->Controls->Add(text);
	//text->KeyDown += gcnew KeyEventHandler(this, &DataGridSelfMade::textboxEnter);
	//text->LostFocus += gcnew EventHandler(this, &DataGridSelfMade::textboxLostFocus);
	text->BackColor = Color::Aqua;
	text->Visible = false;
}



/*
関数名:Cell_click
概要:セルがクリックされたときの関数
引数:int row　セルの行, int col　セルの列
返却値:なし
作成日:9月10日
作成者:成田修之
*/
Void narita::DataGridSelfMade::cell_click(int row, int col)
{
	//行列が無効な値なら
	if (row < 0 || col < 0) {
		//処理をやめる
		return;
	}

	//それまでのカレントのセルが有効なセルであるなら
	if (0 <= currentCell->row && 0 <= currentCell->col) {
		//その行をもとの色で描く
		drawRow(currentCell, Brushes::White);
	}

	//カレントのセルを引数の値にする
	currentCell->row = row;
	currentCell->col = col;
	
	//カレントの行を水色で描く
	drawRow(currentCell, Brushes::Aqua);

	//描画を促して変更を反映
	pictureBox->Invalidate();
}

/*
関数名:cell_click
概要:セルがクリックされたときの関数(オーバーロード)
引数:Cell^ cell セル
返却値:なし
作成者:成田修之
作成日:9月15日(金)
*/
Void narita::DataGridSelfMade::cell_click(Cell ^ cell)
{
	//引数のセルの行数列数で同じ関数を呼び出す。
	cell_click(cell->row, cell->col);
}

/*
関数名:cell_Click
概要:セルがクリックされたときの動作
引数:無し
返却値:なし
作成日:9月9日
作成者:成田修之
*/
Void DataGridSelfMade::cell_click(System::EventArgs^ e)
{
	int row = ((MouseEventArgs^)e)->Y / this->cellHeight;
	int col = ((MouseEventArgs^)e)->X / this->cellWidth;

	this->cell_click(row, col);

}

/*
関数名:drawCell
概要:セルを描画する
引数:int row 行
	int col 列
	Brush^ color　セルの色
返却値:無し
作成日:10月17日(火)
作成者:成田修之
*/
Void narita::DataGridSelfMade::drawCell(int row, int col, Brush ^ color)
{
	//行列が有効な値でない
	if (0 > row || 0 > col) {
		//処理をやめる
		return;
	}
	//セルとなる四角形を作製する
	RectangleF^ rect = gcnew RectangleF(col * this->cellWidth, row * this->cellHeight, this->cellWidth - 1, this->cellHeight - 1);
	//引数の行のデータを取得する
	ChainData* rowData = cell->getRow(row);
	//セルの値を格納する変数を用意
	String^ value;
	//一列目についての時

		//その列の値を格納する
		value = rowData->getValue(col + 1).ToString();

	//セルの区切りの線を描く
	graphic->DrawLine(cellFramePen, Point(col * cellWidth, row * cellHeight), Point(col * cellWidth, (row + 1) * cellHeight));
	//四角形を引数の色で満たしておく
	graphic->FillRectangle(color, *rect);
	//取得した文字列を四角形に描く
	graphic->DrawString(value, font, Brushes::Black, *rect);
}

/*
関数名:drawCell(オーバーライド)
概要:セルを選択して描画する
引数:Cell^　描画したいセル
	Brush^　その際の色
返却値:無し
作成日:10月17日(火)
作成者:成田修之
*/
Void narita::DataGridSelfMade::drawCell(Cell ^ cell, Brush ^ color)
{
	//オーバーライド先に合わせてその関数を呼ぶ
	drawCell(cell->row, cell->col, color);
}

/*
関数名:drawRow
概要:行を描画する
引数:int row 描画する行
	Brush^　色
返却値:無し
作成日:10月17日(火)
作成者:成田修之
*/
Void narita::DataGridSelfMade::drawRow(int row, Brush ^ color)
{
	//引数の行が無効な値なら
	if (0 > row) {
		//処理をやめる
		return;
	}

	//4列分繰り返す
	for (int i = 0; i < 4; i++) {
		//各セルを描く
		drawCell(row, i, color);
	}
}

/*
関数名:drawRow(オーバーライド)
概要:セルを選択して行を描画する
引数:Cell^　セル
	Brush＾　色
返却値:無し
作成日:10月17日(火)
作成者:成田修之
*/
Void narita::DataGridSelfMade::drawRow(Cell ^ cell, Brush ^ color)
{
	//行と引数の色で描く
	drawRow(cell->row, color);
}

/*
関数名:Paint
概要:すべてのセルを描画する
引数:無し
返却値:無し
作成日:10月17日(火)
作成者:成田修之
*/
Void narita::DataGridSelfMade::Paint()
{
	//行か列のどちらかが0なら表示するものはないので何もしない
	if (rowCount == 0 || colCount == 0) {
		return;
	}
	//ピクチャーボックスの大きさを設定されている行数列数に合わせる
	pictureBox->Size = System::Drawing::Size(colCount * cellWidth, rowCount * cellHeight);
	//ピクチャーボックスの大きさに合わせて描画先のオブジェクトを生成しなおす
	pictureBox->Image = gcnew Bitmap(pictureBox->Width, pictureBox->Height);
	//その描画先に描画するオブジェクトを作成
	graphic = Graphics::FromImage(pictureBox->Image);

	//行数分繰り返す
	for (int i = 0; i < rowCount; i++) {
		//行ごとに描く
		drawRow(i, Brushes::White);
		//行ごと線を描画
		graphic->DrawLine(cellFramePen, Point(0, (i + 1) * cellHeight), Point(colCount * cellWidth, (i + 1) * cellHeight));
	}

	//＠修正　カレントのセルのある行がなくなった時セルの値を取得できずに
	//例外が出るので行数列数より多いときはカレントのセルを描画しない
	if (currentCell->row < rowCount && currentCell->col < colCount) {
		//カレントのセルについて描画する
		drawCell(currentCell, Brushes::Aqua);
	}
	
	return Void();
}
