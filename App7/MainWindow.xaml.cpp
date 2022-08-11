#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::App7::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        m_explorerItems = winrt::single_threaded_observable_vector<App7::Item>();
        for (int i = 0; i < 100000; i++) {
            m_explorerItems.Append(winrt::make<Item>(L"Item name"));
        }

    }

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        m_explorerItems.GetAt(0).Name(L"New Item name");
    }

    winrt::Windows::Foundation::Collections::IObservableVector<App7::Item> MainWindow::ExplorerItems()
    {
        return m_explorerItems;
    }

}
