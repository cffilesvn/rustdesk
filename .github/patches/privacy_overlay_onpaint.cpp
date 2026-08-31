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
	Gdiplus::Font subtitleFont(&fontFamily, 22, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
	Gdiplus::SolidBrush brush(Gdiplus::Color(255, 255, 255, 255));
	Gdiplus::StringFormat format;
	format.SetAlignment(Gdiplus::StringAlignmentCenter);
	format.SetLineAlignment(Gdiplus::StringAlignmentCenter);

	Gdiplus::RectF titleRect(40, client_h * 0.30f, client_w - 80, 72);
	Gdiplus::RectF subRect(40, client_h * 0.30f + 80, client_w - 80, 72);
	Gdiplus::RectF warnRect(40, client_h * 0.30f + 160, client_w - 80, 48);
	graphics.DrawString(L"UNLOCK1S", -1, &titleFont, titleRect, &format, &brush);
	graphics.DrawString(
		L"D\u1ECBch v\u1EE5 \u0111ang x\u1EED l\u00FD, vui l\u00F2ng ki\u00EAn nh\u1EABn ch\u1EDD \u0111\u1EE3i",
		-1,
		&subtitleFont,
		subRect,
		&format,
		&brush);
	graphics.DrawString(
		L"Kh\u00F4ng thao t\u00E1c v\u00E0o m\u00E1y t\u00EDnh",
		-1,
		&subtitleFont,
		warnRect,
		&format,
		&brush);
}
