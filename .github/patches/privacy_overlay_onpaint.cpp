VOID OnPaintGdiPlus(HWND hwnd, HDC hdc)
{
	if (!hdc)
	{
		return;
	}

	RECT rcClient;
	if (FALSE == GetClientRect(hwnd, &rcClient))
	{
		return;
	}

	Gdiplus::Graphics graphics(hdc);
	graphics.Clear(Gdiplus::Color::Black);
	graphics.SetTextRenderingHint(Gdiplus::TextRenderingHintAntiAlias);

	const auto client_w = static_cast<Gdiplus::REAL>(rcClient.right - rcClient.left);
	const auto client_h = static_cast<Gdiplus::REAL>(rcClient.bottom - rcClient.top);

	Gdiplus::FontFamily fontFamily(L"Segoe UI");
	Gdiplus::Font titleFont(&fontFamily, 48, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
	Gdiplus::Font subtitleFont(&fontFamily, 24, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
	Gdiplus::SolidBrush brush(Gdiplus::Color(255, 255, 255, 255));
	Gdiplus::StringFormat format;
	format.SetAlignment(Gdiplus::StringAlignmentCenter);
	format.SetLineAlignment(Gdiplus::StringAlignmentCenter);

	Gdiplus::RectF titleRect(0, client_h * 0.38f, client_w, 72);
	Gdiplus::RectF subRect(0, client_h * 0.38f + 80, client_w, 48);
	graphics.DrawString(L"UNLOCK1S Desk", -1, &titleFont, titleRect, &format, &brush);
	graphics.DrawString(L"Remote session in progress", -1, &subtitleFont, subRect, &format, &brush);
}
