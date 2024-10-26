#include "pch.h"
#include "main.h"
#if __has_include("main.g.cpp")
#include "main.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::DialogBox::implementation
{
    int32_t main::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void main::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void main::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
