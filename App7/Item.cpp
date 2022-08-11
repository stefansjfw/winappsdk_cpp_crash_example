#include "pch.h"
#include "Item.h"
#include "Item.g.cpp"

namespace winrt::App7::implementation
{
    Item::Item(hstring const& name)
    {
        m_name = name;
    }
    hstring Item::Name()
    {
        return m_name;
    }
    void Item::Name(hstring const& value)
    {
        if (m_name != value)
        {
            m_name = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Name" });
        }
    }
    winrt::event_token Item::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }

    void Item::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
