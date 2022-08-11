#pragma once
#include "Item.g.h"

namespace winrt::App7::implementation
{
    struct Item : ItemT<Item>
    {
        Item() = default;

        Item(hstring const& name);
        hstring Name();
        void Name(hstring const& value);
        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
    private:
        hstring m_name;
        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}
namespace winrt::App7::factory_implementation
{
    struct Item : ItemT<Item, implementation::Item>
    {
    };
}
