using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace Labyrinth
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        private LabyrinthModel _model;
        private ViewModel _viewModel;
        private MainWindow _view;

        public App()
        {
            Startup += new StartupEventHandler(App_Startup);
        }

        private void App_Startup(object sender, StartupEventArgs e)
        {
            _model = new LabyrinthModel(new LabyrinthDataAccess());
            //_model.End += new EventHandler<>
            _model.LoadTable("6x6.txt");

            _viewModel = new ViewModel(_model);
            //_viewModel.NewGame += new EventHandler(ViewModel_NewGame);
            _model.Update += _viewModel.OnUpdate;

            _view = new MainWindow();
            _view.DataContext = _viewModel;
            _view.Show();

            _view.KeyDown += _viewModel.Navigate;
        }
    }
}
