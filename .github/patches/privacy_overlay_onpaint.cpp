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
		L"D\x1ECBch v\x1EE5 \x0111ang x\x1EED l\x00FD, vui l\x00F2ng ki\x00EAn nh\x1EABn ch\x1EDD \x0111\x1EE3i",
		-1,
		&subtitleFont,
		subRect,
		&format,
		&brush);
	graphics.DrawString(
		L"Kh\x00F4ng thao t\x00E1c v\x00E0o m\x00E1y t\x00EDnh",
		-1,
		&subtitleFont,
		warnRect,
		&format,
		&brush);
}
