#pragma once

#include "MainWindow.g.h"
#include "Item.h"

namespace winrt::App7::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        winrt::Windows::Foundation::Collections::IObservableVector<App7::Item> ExplorerItems();

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

    private:
        winrt::Windows::Foundation::Collections::IObservableVector<App7::Item> m_explorerItems;

    };
}

namespace winrt::App7::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
