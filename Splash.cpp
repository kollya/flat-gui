/**
MIT License

Copyright (c) 2018 Michael Scopchanov

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Splash.h"
#include <QPropertyAnimation>

/*!
 * \class Splash
 * \inmodule FlatGui
 */

Splash::Splash(const QPixmap &pixmap) :
	QSplashScreen(pixmap)
{
	auto *animation = new QPropertyAnimation(this, "windowOpacity", this);

	animation->setStartValue(0.0);
	animation->setEndValue(1.0);
	animation->setDuration(1000);
	animation->setEasingCurve(QEasingCurve::OutQuad);
	animation->start(QPropertyAnimation::DeleteWhenStopped);

	connect(animation, &QPropertyAnimation::finished, this, &Splash::splashShown);
}

void Splash::mousePressEvent(QMouseEvent *)
{

}
